class Solution {
public:
    int smallest(vector<int>&nums){
        int small=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<small)
                small=nums[i];
        }
        return small;
    }
    int totalSum(vector<int>&nums){
        int sum=0;
        for(int i=0;i< nums.size();i++){
            sum+=nums[i];
        }
        return sum;
    }
    int minMoves(vector<int>& nums) {
        int sum= totalSum(nums);
        int small=smallest(nums);
        int steps= sum-(nums.size()*small);
        return steps;
        }
};