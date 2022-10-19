class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int len = nums.size();
        // if(len == 1)    return;
        int idx1, idx2;
        for(int i = len-2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                idx1 = i;  //idx1 = 0
                break;
            }                
        }
        if(idx1 < 0)
            reverse(nums.begin(), nums.end());
        else
        {
            for(int j = len-1; j > idx1; j--)
            {
                if(nums[j] > nums[idx1])
                {
                    idx2 = j;  //idx2 = 2
                    break;
                }                
            }
            swap(nums[idx1],nums[idx2]);
            reverse(nums.begin()+(idx1+1), nums.end());
        }        
    }
};
