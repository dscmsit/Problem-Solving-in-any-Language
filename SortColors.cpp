class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(mid <= right)
        {
            if(nums[mid] == 0)
            {
                nums[mid] = nums[left];
                nums[left] = 0;
                left++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                nums[mid] = nums[right];
                nums[right] = 2;
                right--;
            }
        }
    }
};