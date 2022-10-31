class Solution {
public:
    int findMinDiff(int arr[], int n, int m) {
        if(n==0 || m==0){
            return 0;
        }
        sort(arr, arr+n);
        int min_diff= INT_MAX;
        for(int i=0;i<n;i++){
            int diff = arr[i + m - 1] - arr[i];
            if (diff < min_diff)
                    min_diff = diff;
            }
        return min_diff;
        }
};