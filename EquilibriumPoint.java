class Solution {

    
    // a: input array
    // n: size of array
    // Function to find equilibrium point in the array.
    public static int equilibriumPoint(long arr[], int n) {
        int sum = 0;

    	for(int i = 0; i < n; i++)
    	{
    		sum += arr[i];
    	}

    	int l_sum = 0;

    	for(int i = 0; i < n; i++)
    	{
    		if(l_sum == sum - arr[i]){
    		    
    		    return i+1;
    		}

    		l_sum += arr[i];

    		sum -= arr[i];
    	}

    	return -1;
        
    }
}
