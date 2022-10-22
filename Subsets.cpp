class Solution {
public:
    void generateSubset(int idx, vector<int> &ds, vector<int> arr, vector<vector<int>> &res_arr, int n)
    {
        if(idx == n)
        {
            res_arr.push_back(ds);
            return;
        }
        ds.push_back(arr[idx]);
        generateSubset(idx+1,ds,arr,res_arr,n);
        ds.pop_back();
        generateSubset(idx+1,ds,arr,res_arr,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        generateSubset(0,ds,nums,ans,(nums.size()));
        return ans;
    }
};