class Solution {
public:
    int findDuplicate(vector<int>& nums) {        
        int n = nums.size();
        int elem;
        
        vector<int> cnt(n,0);
        for(int i = 0; i < n; i++)
        {
            cnt[nums[i]]++;
        }
        for(int i = 0; i < cnt.size(); i++)
        {
            if(cnt[i] > 1)
            {
                elem = i;
                break;
            }
                // elem = i;
        }
        return elem;
    }
};
