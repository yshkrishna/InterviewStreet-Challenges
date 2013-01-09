import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Solution {
	
	int sum=0;
	
	
	public void solve(String input)
	{
		sum=0;
		
	/*
	 * Add suffixes to Array
	 */		
       char[] input_array = input.toCharArray();
       sum+=input_array.length;
       int j;
       
		for(int i=1;i<input_array.length;i++) //suffix
		{	
			for(j=0;j<input_array.length-i;j++)
			{
			if(input_array[j]!=input_array[j+i])
				break;
			}
			sum+=j;
		}
	}
				
	public static void main(String args[]) {
		
		Solution main = new Solution();
		
	    try {
	        BufferedReader br = 
	          new BufferedReader(new InputStreamReader(System.in));
	        
	        /*
	         * Handle T
	         */
	        String T = br.readLine();
	        int T_int = Integer.parseInt(T);
	        if(T_int>10 || T_int<1)
	        	throw new Exception("T is not within bounds 1<=T<=10");
	        
	        /*
	         * Main Body
	         */
	        for(int i=0;i<T_int;i++)
	        {
	        String user_input =br.readLine(); //current String for the line
	        if(user_input.length()>100000)
	        	throw new Exception("String length is greater than 100,000 characters");
	        	       
	        main.solve(user_input);

	        System.out.println(main.sum);
	        }
	    }
	    catch (Exception e)
	    {
	        System.err.println("Error: " + e.getMessage());
	    }	  
	}
}
