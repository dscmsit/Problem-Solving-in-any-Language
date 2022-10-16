// LEETCODE 315.  Count of Smaller Numbers After Self { Hard } {Array}

// Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].
  
// Example 1:
// Input: nums = [5,2,6,1]
// Output: [2,1,1,0]
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
  
// Example 2:
// Input: nums = [-1]
// Output: [0]

// Example 3:
// Input: nums = [-1,-1]
// Output: [0,0]

### Solution

```
class Solution {
    public class TreeNode
        {
        int val;
        int count = 1;
        TreeNode left;
        TreeNode right;
        
        TreeNode(int val)
            {
            this.val = val;
            }
        }
    
    public int insert_BST(TreeNode root, int val)
        {
        int sum = 0;
        while(true)
            {
            if(val <= root.val)
                {
                root.count++;
                if(root.left != null)
                    root = root.left;
                
                else
                    {
                    root.left = new TreeNode(val);
                    break;
                    }
                }
            else
                {
                sum+= root.count;
                
                if(root.right != null)
                    root = root.right;
                
                else
                    {
                    root.right = new TreeNode(val);
                    break;
                    }
                }
            }
        return sum;
        }
    public List<Integer> countSmaller(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        if(nums == null || nums.length ==0)
            return ans;
        TreeNode root = new TreeNode(nums[nums.length-1]);
        ans.add(0);
        for(int i = nums.length-2; i >=0; i--)
            {
            int count = insert_BST(root, nums[i]);
            ans.add(count);
            }
        Collections.reverse(ans);
        return ans;
        
    }
} 
```
