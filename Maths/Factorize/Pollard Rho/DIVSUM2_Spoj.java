import java.io.*;
import java.util.*;
import java.math.*;
import java.security.*;

class DIVSUM2 {
	
	final static BigInteger TWO=new BigInteger("2");
	final static SecureRandom rand_generator=new SecureRandom();
	static BigInteger c,sloww,fastt;
	static Vector<Long> factors;
	static Long ans,poww,summ;
	
	public static BigInteger pollard_rho(BigInteger num)
	{
		if(num.mod(TWO).compareTo(BigInteger.ZERO)==0)
		{
			return TWO;
		}
		BigInteger ret;
		
		c=new BigInteger(num.bitLength(),rand_generator);
		sloww=new BigInteger(num.bitLength(),rand_generator);
		fastt=sloww;
		
		do
		{
			sloww=sloww.multiply(sloww).mod(num).add(c).mod(num);
			fastt=fastt.multiply(fastt).mod(num).add(c).mod(num);
			fastt=fastt.multiply(fastt).mod(num).add(c).mod(num);
			ret=sloww.subtract(fastt).gcd(num);
		}
		while(ret.compareTo(BigInteger.ONE)==0);		
		
		return ret;
	}
	
	public static void factorize(BigInteger num)
	{
		if(num.compareTo(BigInteger.ONE)==0)
		{
			return;
		}
		
		if(num.isProbablePrime(20))
		{
			factors.add(num.longValue());
			return;
		}
		
		BigInteger divisor=pollard_rho(num);
		
		factorize(divisor);
		factorize(num.divide(divisor));
		
	}

	public static void main(String[] args) {
		try
		{
			BufferedReader br = null;
			br = new BufferedReader(new FileReader(".\\Text\\DIVSUM2.txt"));
			//br = new BufferedReader(new InputStreamReader(System.in));
			
			int cases=Integer.parseInt(br.readLine());
			
			while(cases-- >0)
			{
				long num=Long.parseLong(br.readLine());
				factors=new Vector<Long>();
				factorize(BigInteger.valueOf(num));
				Collections.sort(factors);
				
				ans=1L;
				
				for(int i=0;i<factors.size();++i)
				{
					poww=1L;
					summ=1L;
					
					for(int j=i;j<factors.size() && factors.get(j).equals(factors.get(i));++j)
					{
						poww*=factors.get(j);
						summ+=poww;
						i=j;
					}
					ans*=summ;							
				}
				
				System.out.println(ans-num);
			}
			
		}
		catch(Exception e)
		{
			
		}
	}

}
