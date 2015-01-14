import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class Solution 
{
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] deps = new int[n];
		int[] par = new int[n];
		Arrays.fill(par, -1);
		int[] ft = new int[n+1];
		
		for(int i = 0;i < n;i++)
		{
			int v = a[i]-1;
			int bef = before(ft, v);
			int aft = after(ft, v);
			
			if(bef == -1)
			{
				if(aft == -1)
				{
					deps[v] = 0;
					par[v] = -1;
				}
				else
				{
					deps[v] = deps[aft] + 1;
					par[v] = aft;
				}
			}
			else
			{
				if(aft == -1)
				{
					deps[v] = deps[bef] + 1;
					par[v] = bef;
				}
				else
				{
					if(deps[bef] > deps[aft])
					{
						deps[v] = deps[bef] + 1;
						par[v] = bef;
					}
					else
					{
						deps[v] = deps[aft] + 1;
						par[v] = aft;
					}
				}
			}
			addFenwick(ft, v, 1);
		}
		
		int[][] g = parentToG(par);
		int[][] spar = logstepParents(par);
		int[][] pars = parents3(g, a[0]-1);
		//int[] dep = pars[2];
		int[] dep = deps;
		
		int[] cpar = new int[n];
		//separate(g, 0, new boolean[n], new int[n], new int[n], new int[n], cpar, -1);
		separate(g, a[0]-1, new boolean[n], new int[n], new int[n], new int[n], cpar, -1);
		
		int[][] cg = parentToG(cpar);
		
		for(int[] row : cg)
		{
			Arrays.sort(row);
		}
		
		long[] dessum = new long[n];
		long[][] dessums = new long[n][];
		int[] desnum = new int[n];
		int[][] desnums = new int[n][];
		
		for(int i = 0;i < n;i++)
		{
			dessums[i] = new long[cg[i].length];
			desnums[i] = new int[cg[i].length];
		}
		
		long gret = 0;
		for(int i = 0;i < n;i++)
		{
			int v = a[i]-1;
			long ret = 0;
			for(int w = v, pre = -1;w != -1;pre = w, w = cpar[w])
			{
				int lca = lca2(v, w, spar, dep);
				int d = dep[v] + dep[w] - 2*dep[lca];
				int dir = Arrays.binarySearch(cg[w], pre);
				int num = desnum[w];
				long sum = dessum[w];
				if(dir >= 0)
				{
					num -= desnums[w][dir];
					sum -= dessums[w][dir];
				}
				ret += (long)d*num + sum;
				
				desnum[w]++;
				dessum[w] += d;
				if(dir >= 0)
				{
					desnums[w][dir]++;
					dessums[w][dir] += d;
				}
			}
			gret += ret;
			out.println(gret);
		}
	}
	
	public static int[][] parents3(int[][] g, int root) 
	{
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] depth = new int[n];
		//depth[0] = 0;
		depth[root] = 0;

		int[] q = new int[n];
		q[0] = root;
		for(int p = 0, r = 1;p < r;p++)
		{
			int cur = q[p];
			for(int nex : g[cur])
			{
				if(par[cur] != nex)
				{
					q[r++] = nex;
					par[nex] = cur;
					depth[nex] = depth[cur] + 1;
				}
			}
		}
		return new int[][] { par, q, depth };
	}
	
	public static int lca2(int a, int b, int[][] spar, int[] depth) {
		if(depth[a] < depth[b]){
			b = ancestor(b, depth[b] - depth[a], spar);
		}else if(depth[a] > depth[b]){
			a = ancestor(a, depth[a] - depth[b], spar);
		}

		if(a == b)
			return a;
		int sa = a, sb = b;
		for(int low = 0, high = depth[a], t = Integer.highestOneBit(high), k = Integer
				.numberOfTrailingZeros(t);t > 0;t >>>= 1, k--){
			if((low ^ high) >= t){
				if(spar[k][sa] != spar[k][sb]){
					low |= t;
					sa = spar[k][sa];
					sb = spar[k][sb];
				}else{
					high = low | t - 1;
				}
			}
		}
		return spar[0][sa];
	}

	protected static int ancestor(int a, int m, int[][] spar) {
		for(int i = 0;m > 0 && a != -1;m >>>= 1, i++){
			if((m & 1) == 1)
				a = spar[i][a];
		}
		return a;
	}

	public static int[][] logstepParents(int[] par) {
		int n = par.length;
		int m = Integer.numberOfTrailingZeros(Integer.highestOneBit(n - 1)) + 1;
		int[][] pars = new int[m][n];
		pars[0] = par;
		for(int j = 1;j < m;j++){
			for(int i = 0;i < n;i++){
				pars[j][i] = pars[j - 1][i] == -1 ? -1
						: pars[j - 1][pars[j - 1][i]];
			}
		}
		return pars;
	}
	
	static void separate(int[][] g, int root, boolean[] sed, int[] par, int[] ord, int[] des, int[] cpar, int prev)
	{
		// parent and level-order
		ord[0] = root;
		par[root] = -1;
		int r = 1;
		for(int p = 0;p < r;p++) 
		{
			int cur = ord[p];
			for(int nex : g[cur])
			{
				if(par[cur] != nex && !sed[nex])
				{
					ord[r++] = nex;
					par[nex] = cur;
				}
			}
		}
		// if(r == 1)return;
		
		// DP and find a separator
		int sep = -1; // always exists
		outer:
		for(int i = r-1;i >= 0;i--)
		{
			int cur = ord[i];
			des[cur] = 1;
			for(int e : g[cur])
			{
				if(par[cur] != e && !sed[e])
					des[cur] += des[e];
			}
			
			if(r-des[cur] <= r/2)
			{
/*
				for(int e : g[cur])
				{
					if(par[cur] != e && !sed[e] && des[e] >= r/2+1)
						continue outer;
				}
*/				
				sep = cur;
				break;
			}
		}
		
		sed[sep] = true;
		cpar[sep] = prev;
		
		for(int e : g[sep])
		{
			if(!sed[e])
				separate(g, e, sed, par, ord, des, cpar, sep);
		}
	}
	
	public static int[][] parentToG(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++)
		{
			if(par[i] >= 0)
			{
				ct[i]++;
				ct[par[i]]++;
			}
		}
		
		int[][] g = new int[n][];
		for(int i = 0;i < n;i++)
		{
			g[i] = new int[ct[i]];
		}
		for(int i = 0;i < n;i++)
		{
			if(par[i] >= 0)
			{
				g[par[i]][--ct[par[i]]] = i;
				g[i][--ct[i]] = par[i];
			}
		}
		return g;
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0 || i < 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int findGFenwick(int[] ft, int v)
	{
		int i = 0;
		int n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0 && i < n;b >>= 1)
		{
			if(i + b < n)
			{
				int t = i + b;
				if(v >= ft[t])
				{
					i = t;
					v -= ft[t];
				}
			}
		}
		return v != 0 ? -(i+1) : i-1;
	}
	
	public static int before(int[] ft, int x)
	{
		int u = sumFenwick(ft, x-1);
		if(u == 0)return -1;
		return findGFenwick(ft, u-1)+1;
	}
	
	public static int after(int[] ft, int x)
	{
		int u = sumFenwick(ft, x);
		int f = findGFenwick(ft, u);
		if(f+1 >= ft.length-1)return -1;
		return f+1;
	}
	
	
	public static void main(String[] args) throws Exception
	{
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}	
	
	private static byte[] inbuf = new byte[1024];
	static int lenbuf = 0, ptrbuf = 0;
	
	private static int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private static boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	
	private static int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private static int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
}
