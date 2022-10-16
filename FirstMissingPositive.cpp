// LEETCODE 41. First Missing Positive { Hard } { Array }

// Given an unsorted integer array nums, return the smallest missing positive integer.

// You must implement an algorithm that runs in O(n) time and uses constant extra space. 

// Example 1:
// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.

// Example 2:
// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.

// Example 3:
// Input: nums = [7,8,9,11,12]
// Output: 1
// Explanation: The smallest positive integer 1 is missing.
 
// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1

### Solution

```
class Solution {
    
     static int segregate(int arr[], int size) 
    { 
        int j = 0, i; 
        for(i = 0; i < size; i++) 
        { 
           if (arr[i] <= 0)   
           { 
               int temp; 
               temp = arr[i]; 
               arr[i] = arr[j]; 
               arr[j] = temp; 
               j++;   
           } 
        } 
       
        return j; 
    } 
       
    static int findMissingPositive(int arr[], int size) 
    { 
      int i; 
       
      for(i = 0; i < size; i++) 
      { 
        int x = Math.abs(arr[i]); 
        if(x - 1 < size && arr[x - 1] > 0) 
          arr[x - 1] = -arr[x - 1]; 
      } 

      for(i = 0; i < size; i++) 
        if (arr[i] > 0) 
          return i+1;  
       
      return size+1; 
    } 
       
    static int findMissing(int arr[], int size) 
    { 
       int shift = segregate (arr, size); 
       int arr2[] = new int[size-shift]; 
       int j=0; 
       for(int i=shift;i<size;i++) 
           { 
               arr2[j] = arr[i]; 
               j++; 
           }     
       return findMissingPositive(arr2, j); 
    } 
    
    public int firstMissingPositive(int[] arr) {
        
        int n = arr.length; 
        int missing = findMissing(arr, n); 
        
        return missing;
       
    }  
}
```
