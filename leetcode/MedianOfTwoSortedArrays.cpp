// LEETCODE 4. Median of Two Sorted Arrays { Hard } { Arrays }

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 
// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

### Solution

```
class Solution {
    public double findMedianSortedArrays(int[] A, int[] B) {
        int m = A.length;
        int n = B.length;
        if(m > n)
            {
            int[] temp = A; A = B; B = temp;
            int tmp = m; m = n; n = tmp;
        }
        
        int imin = 0;
        int imax = m;
        int minR = 0;
          int maxL = 0;
        int half = ((m+n +1)/2 );
        
        while(imin <= imax)
        {
            int i =  (imin + imax) / 2;
            int j =  half- i;
            
            if(i < imax && B[j-1] > A[i])
                imin = i +1;
            
            else if (i > imin && A[i-1] > B[j])
                imax = i -1;
            
            else
            {
              maxL = 0;
                
                if( i == 0)
                    maxL = B[j-1];
                else if (j ==0)
                    maxL = A[i-1];
                
                else
                    maxL = Math.max(A[i-1], B[j-1]);
                
                if((m + n) %2 == 1) return maxL;       
                
                if( i == m)
                    minR= B[j];
                else if (j == n)
                    minR = A[i];
                else
                    minR = Math.min(A[i], B[j]);
               return  (minR + maxL )/ 2.0;
            }
   
        }        
         return 0.0;
            
    }
}
```
