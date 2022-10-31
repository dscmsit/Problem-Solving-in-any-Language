import java.util.*;


class LongestSubarrayWithGivenSum {
    
    static int longestSubarray(int n, int[] arr, int sum) {
        // We will use prefix sum here 
        int pre_sum = 0, len = 0;
        HashMap<Integer,Integer> map  = new HashMap<>();

        for(int i = 0; i < n; i++) {
            pre_sum += arr[i];
            // Condition if prefix sum starts from 0 index
            if(pre_sum == sum)  len = Math.max(len, i+1);
            
            if(map.containsKey(pre_sum - sum)) {
                len = Math.max(len, i - map.get(pre_sum - sum));
            }
            // Only 1st occurence of pre_sum is taken so as to consider longest subarray
            if(!map.containsKey(pre_sum))    map.put(pre_sum,i);

        }
        return len;
    }

    //Driver code
    public static void main (String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int sum = sc.nextInt();
        int n = sc.nextInt();
        int arr[] = new int[n];
        
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println(longestSubarray(n, arr, sum));
        sc.close();
    }


}
