class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        vector<int> ans;
        while (i < j)
        {
            if(nums[i]+nums[j] == target)
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(nums[i]+nums[j] > target)
                j--;
            else
                i++;
        }
        return ans;
        
        
    }
};
