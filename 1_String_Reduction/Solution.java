import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {
		
	int min = 1; 
	int sol = 1; 
			
	public String convert(String to_convert)
	{
		String ret = "b";
		if (to_convert.equalsIgnoreCase("ab")|| to_convert.equalsIgnoreCase("ba"))
		{
			ret="c";
		}
		else if (to_convert.equalsIgnoreCase("bc")|| to_convert.equalsIgnoreCase("cb"))
		{
			ret="a";
		}
		return ret;
	}
					
	public boolean solve(String input)
	{
		min=input.length();
	
		if(input.length()==1) //one letter base case
		{
			sol=1;
			return true;
		}
		else if(input.length()==2 && input.charAt(0)==input.charAt(1)) //2 letters the same case
		{
			sol=2;
			return true;
		}
												        
		
		//Loop through entire string (-1 because we need 2 letters adjacent)
		for(int i=0;i<input.length()-1;i++)
		{
			if(input.charAt(i)!=input.charAt(i+1)) //if letters are the same do nothing
			{
				String two_letters = new String(); //String to hold two letters in question
				two_letters += input.charAt(i);
				two_letters += input.charAt(i+1);
				String converted_letters = convert(two_letters);
				String before = ""; //handle the string prior to two characters in question
				String after = ""; //handle the string after the two characters in question
																																								        		
				//Dealing with characters coming before the two letters in question        		
				if(i==1)
				{
					before += input.charAt(0);
				}
				else if (i>1)
				{
					before += input.substring(0,i);
				}
				
				//Dealing with the characters after the two letters in question
				if(i+2==input.length()-1)
				{
					after += input.charAt(input.length()-1);
				}
				else if(i+2<input.length()-1)
				{
					after += input.substring(i+2,input.length());
				}
				
				//Combining strings and recursively calling
				String new_input = before + converted_letters + after;
				if(solve(new_input)==true)
				{
					min=Math.min(min, sol);
					return true;
				}
				
			}//end if       	
		}//end for

		return false;    			
	}

	/*
	 * Running Main
	 */
	public static void main(String args[])
	{
		Solution main = new Solution();
		
		try
		{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
												        
			
			//Handle T
			String T = br.readLine();
			int T_int = Integer.parseInt(T);
			if(T_int>100 || T_int<1)
			{
				throw new Exception("T is not within bounds 1<=T<=100");
			}
			
			//Main Body
			for(int i=0;i<T_int;i++)
			{
				String user_input =br.readLine(); //current String for the line

				if(user_input.length()>100)
				{
					throw new Exception("String length is greater than 100 characters");
				}
				
				main.solve(user_input);
				System.out.println(main.min);
				
			}
			
		}
		catch (Exception e)
		{
			System.err.println("Error: " + e.getMessage());
			
		}	  
	}
}

