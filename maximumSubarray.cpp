#include <bits/stdc++.h>
using namepsace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int n = nums.size();
        int ans = nums[0], currsum = nums[0];

        for (int i = 1; i < n; i++)
        {

            if (currsum < 0)
            {
                currsum = 0;
            }
            currsum += nums[i];

            ans = max(ans, currsum);
        }

        return ans;
    }
};