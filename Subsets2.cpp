// 90. Leetcode  {MEDIUM}  [Array, Backtracking]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        subsetsWithDup(result, temp, 0, nums);
        return result;
    }

private:
    void subsetsWithDup(vector<vector<int>> &res, vector<int> &temp, int idx, vector<int> &nums)
    {

        res.push_back(temp);

        for (int i = idx; i < nums.size(); i++)
        {
            if (i == idx || nums[i] != nums[i - 1])
            {
                temp.push_back(nums[i]);
                subsetsWithDup(res, temp, i + 1, nums);
                temp.pop_back();
            }
        }
    }
};