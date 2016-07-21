import java.util.*;

// 				x=5					y=3
//						Desired=4


class State
{
	int x;
	int y;
	 public State(int x,int y)
	 {
		 this.x=x;
		 this.y=y;
	 }
}

class WaterJug_DFS {
	
	static int current=0;
	static int end=0;	
	public static void main(String[] args) {
		ArrayList<State> a=new ArrayList<State>();
		
		a.add(0,new State(0,0));	
		
		solve(a,current,end);
		
	}
	
	public static void solve(ArrayList<State> a,int current,int end)
	{
		filla(a,end,0,0);
		fillb(a,end,0,0);
		emptya(a,end,0,0);
		emptyb(a,end,0,0);
		transferatob(a,end,0,0);
		transferbtoa(a,end,0,0);
	}
	
	public static void filla(ArrayList<State> a,int end,int x,int y)
	{
		System.out.println("FILLA	"+x+"\t"+y);
		if(x==4|| y==4)
		{
			System.out.println(x+"\t"+y);
			System.exit(0);
		}
		if(x==5)
		{
			return;
		}
		
		State s=new State(5,y);
		
		if(isnewState(a,end,s))
		{
			System.out.println(s.x+"\t"+s.y);
			++end;
			a.add(end,s);
		}

		else
		{
			return;
		}
		
		fillb(a,end,s.x,s.y);
		emptya(a,end,s.x,s.y);
		emptyb(a,end,s.x,s.y);
		transferatob(a,end,s.x,s.y);
		transferbtoa(a,end,s.x,s.y);
	}
	
	public static void fillb(ArrayList<State> a,int end,int x,int y)
	{
		System.out.println("FILLB	"+x+"\t"+y);
		if(x==4|| y==4)
		{
			System.out.println(x+"\t"+y);
			System.exit(0);
		}
		
		if(y==3)
		{
			return;
		}
		
		State s=new State(x,3);
		
		if(isnewState(a,end,s))
		{
			System.out.println(s.x+"\t"+s.y);
			++end;
			a.add(end,s);
		}

		else
		{
			return;
		}
		filla(a,end,s.x,s.y);
		emptya(a,end,s.x,s.y);
		emptyb(a,end,s.x,s.y);
		transferatob(a,end,s.x,s.y);
		transferbtoa(a,end,s.x,s.y);
	}
	
	public static void emptya(ArrayList<State> a,int end,int x,int y)
	{
		System.out.println("EMPTYA	"+x+"\t"+y);
		if(x==4|| y==4)
		{
			System.out.println(x+"\t"+y);
			System.exit(0);
		}
		
		if(x==0)
		{
			return;
		}
		
		State s=new State(0,y);
		
		if(isnewState(a,end,s))
		{
			System.out.println(s.x+"\t"+s.y);
			++end;
			a.add(end,s);
		}

		else
		{
			return;
		}
		filla(a,end,s.x,s.y);
		fillb(a,end,s.x,s.y);
		emptyb(a,end,s.x,s.y);
		transferatob(a,end,s.x,s.y);
		transferbtoa(a,end,s.x,s.y);
	}
	
	public static void emptyb(ArrayList<State> a,int end,int x,int y)
	{
		System.out.println("EMPTYB	"+x+"\t"+y);
		if(x==4|| y==4)
		{
			System.out.println(x+"\t"+y);
			System.exit(0);
		}
		
		if(y==0)
		{
			return;
		}
		
		State s=new State(x,0);
		
		if(isnewState(a,end,s))
		{
			System.out.println(s.x+"\t"+s.y);
			++end;
			a.add(end,s);
		}

		else
		{
			return;
		}
		filla(a,end,s.x,s.y);
		fillb(a,end,s.x,s.y);
		emptya(a,end,s.x,s.y);
		transferatob(a,end,s.x,s.y);
		transferbtoa(a,end,s.x,s.y);
	}
	
	public static void transferatob(ArrayList<State> a,int end,int x,int y)
	{
		System.out.println("A TO B	"+x+"\t"+y);
		if(x==4|| y==4)
		{
			System.out.println(x+"\t"+y);
			System.exit(0);
		}
		
		if(x==0)
		{
			return;
		}
		
		if(x+y>=3)
		{
			x=x+y-3;
			y=3;
		}
		else
		{
			y=x+y;
			x=0;
		}
		
		State s=new State(x,y);
		
		if(isnewState(a,end,s))
		{
			System.out.println(s.x+"\t"+s.y);
			++end;
			a.add(end,s);
		}

		else
		{
			return;
		}
		filla(a,end,s.x,s.y);
		fillb(a,end,s.x,s.y);
		emptya(a,end,s.x,s.y);
		emptyb(a,end,s.x,s.y);
		transferbtoa(a,end,s.x,s.y);
	}
	
	public static void transferbtoa(ArrayList<State> a,int end,int x,int y)
	{
		System.out.println("B TO A	"+x+"\t"+y);
		if(x==4|| y==4)
		{
			System.out.println(x+"\t"+y);
			System.exit(0);
		}
		
		if(y==0)
		{
			return;
		}
		
		if(x+y>=5)
		{
			y=x+y-5;
			x=5;
		}
		else
		{
			x=x+y;
			y=0;
		}
		
		State s=new State(x,y);
		
		if(isnewState(a,end,s))
		{
			System.out.println(s.x+"\t"+s.y);
			++end;
			a.add(end,s);
		}
		
		else
		{
			return;
		}
		
		filla(a,end,s.x,s.y);
		fillb(a,end,s.x,s.y);
		emptya(a,end,s.x,s.y);
		emptyb(a,end,s.x,s.y);
		transferatob(a,end,s.x,s.y);
	}	
	
	
	public static boolean isnewState(ArrayList<State> a,int end,State s)
	{
		int i=0;
		State t;
		boolean neww=true;
		
		for(i=0;i<=end;++i)
		{
			t=a.get(i);
			if(t.x==s.x && t.y==s.y)
			{
				neww=false;
				break;
			}
		}
		
		return neww;
	}

}