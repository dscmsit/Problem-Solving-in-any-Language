// Using BoyeMajorityElementAlgorithm
// Majority element is the elemt which occcurs more than N/2 times
public class MajorityElement { 
    static int findMajority(int arr[], int n)   //1st phase, it is used to choose a majority candidate
    {
    	int res = 0, count = 1;

    	for(int i = 1; i < n; i++)
    	{
    		if(arr[res] == arr[i])
    			count++;
    		else 
    			count --;

    		if(count == 0)
    		{
    			res = i; count = 1;
    		}
    	}
//  2nd Phase, used to check if the candidate is really majority or not i.e. it occurs N/2 or not.
//This can be skipped if it is confirmed that majority element exists
    	count = 0;

    	for(int i = 0; i < n; i++)
    		if(arr[res] == arr[i])
    			count++;

    	if(count <= n /2)
    		res = -1;

    	return res; 
    }


    public static void main(String args[]) 
    { 
       int arr[] = {8, 8, 6, 6, 6, 4, 6}, n = 7;

       System.out.println(findMajority(arr, n));

    } 

}