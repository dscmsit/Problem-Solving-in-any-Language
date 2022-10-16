// 78. Leetcode  {MEDIUM}  [Array, Backtracking]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> allsubset;

    void generate(vector<int> &tempset, int i, vector<int> &nums)
    {

        if (i == nums.size())
        {
            allsubset.push_back(tempset);
            return;
        }

        // ith element not included in subset
        generate(tempset, i + 1, nums);

        // ith element to be included in subset
        tempset.push_back(nums[i]);
        generate(tempset, i + 1, nums);
        tempset.pop_back();
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<int> empty;
        generate(empty, 0, nums);
        sort(allsubset.begin(), allsubset.end());
        return allsubset;
    }
};