import java.io.*;
import java.math.*;
import java.util.*;


class BIGSEQ {
	
	static int MAXK=101;
	static int k,m;
	static BigInteger ONE=BigInteger.ONE;
	static BigInteger ZERO=BigInteger.ZERO;
	static BigInteger TWO=new BigInteger("2");
	static BigInteger poww[]=new BigInteger[MAXK];
	static BigInteger summ[]=new BigInteger[MAXK];
	
	
	static void pree()
	{
		int i;
		poww[0]=ONE;
		for(i=1;i<=k;++i)
		{
			poww[i]=poww[i-1].add(poww[i-1]);
		}
		
		summ[0]=ZERO;
		
		for(i=1;i<=k;++i)
		{
			summ[i]=summ[i-1].add(summ[i-1]).add(poww[i-1]);
		}
	}
	
	
	static BigInteger numberOf1(BigInteger n)
	{
		int i;
		BigInteger ct=ZERO;
		BigInteger ret=ZERO;
		
		for(i=k;i>0;--i)
		{
			if(poww[i].compareTo(n)<=0)
			{
				n=n.subtract(poww[i]);
				ct=ct.add(ONE);
			}
			if(poww[i-1].compareTo(n)<=0)
			{
				ret=ret.add(summ[i-1]).add(poww[i-1].multiply(ct));
			}
		}
		ret=ret.add(ct);
		if(n.compareTo(ONE)==0)
		{
			ret=ret.add(ONE);
		}
		return ret;
	}
	
	static BigInteger countToNum(BigInteger s)
	{
		BigInteger ret=ZERO;
		
		int i;
		BigInteger ct=ZERO;
		BigInteger tb;
		
		for(i=k;i>0;--i)
		{
			tb=summ[i-1].add(poww[i-1].multiply(ct));
			
			if(tb.compareTo(s)<=0)
			{
				ret=ret.add(poww[i-1]);
				s=s.subtract(tb);
				ct=ct.add(ONE);
			}
		}
		
		if(ct.compareTo(s)<=0)
		{
			ret=ret.add(ONE);
		}		
		
		return ret.subtract(ONE);
	}
	
	static boolean tryy(BigInteger s)
	{
		BigInteger st=ONE;
		int ct=0;
		BigInteger en;
		
		while(st.compareTo(poww[k])<0)
		{
			en=countToNum(numberOf1(st.subtract(ONE)).add(s));
			++ct;
			if(ct>m)
			{
				return false;
			}
			st=en.add(ONE);
		}
		
		return true;
	}
	
	
	static BigInteger solve()
	{
		BigInteger l=ZERO;
		BigInteger r=numberOf1(poww[k].subtract(ONE));
		BigInteger midd;
		
		while(l.add(ONE).compareTo(r)<0)
		{
			midd=l.add(r).divide(TWO);
			if(tryy(midd))
			{
				r=midd;
			}
			else
			{
				l=midd;
			}
		}
		
		return r;
	}
	

	public static void main(String[] args) {
		try
		{
			BufferedReader br = null;
			br = new BufferedReader(new FileReader(".\\Text\\BIGSEQ.txt"));
			//br = new BufferedReader(new InputStreamReader(System.in));
			
			String s[]=br.readLine().split(" ");
			k=Integer.parseInt(s[0]);
			m=Integer.parseInt(s[1]);
			
			//System.out.println(k+" "+m);
			pree();
			
			System.out.println(solve());
					
		}
		catch(Exception e)
		{
			
		}	
	}

}
