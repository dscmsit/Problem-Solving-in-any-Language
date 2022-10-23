// Longest Palindromic Substring - LeetCode Problem 5
// https://leetcode.com/problems/longest-palindromic-substring/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int start;
        int length;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (gap == 0)
                {
                    dp[i][j] = 1;
                }
                else if (gap == 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = 2;
                    }
                }
                else
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1] > 0)
                    {
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j] > 0)
                {
                    start = i;
                    length = dp[i][j];
                }
            }
        }
        return s.substr(start, length);
    }
};