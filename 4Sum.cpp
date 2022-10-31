class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> ans1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long int sum1;
        for (int i = 0; i < n - 3; i++)
        {

            for (int j = i + 1; j < n - 2; j++)
            {

                int l = j + 1, k = n - 1;
                while (l < k)
                {
                    sum1 = (nums[i] * 1LL) + nums[j] + nums[l] + nums[k];

                    if (sum1 > target)
                    {
                        k--;
                    }
                    else if (sum1 == target)
                    {
                        vector<int> v{nums[i], nums[j], nums[l], nums[k]};
                        ans1.insert(v);
                        l++;
                    }
                    else
                        l++;
                }
            }
        }
        vector<vector<int>> ans;
        for (auto it : ans1)
            ans.push_back(it);
        return ans;
    }
};
