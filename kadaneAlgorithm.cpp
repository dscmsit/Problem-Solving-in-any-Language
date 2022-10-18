    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        int mS = arr[0];
        int cS = arr[0];
        for(int i=1; i<n; i++){
            cS=max(cS+arr[i],arr[i]);
            mS=max(mS,cS);
        }
        return mS;
        
    }
};
