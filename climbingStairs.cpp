#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep(int, i, z) for (int i = 0; i < z; i++)

class Solution {
private:
    int climbStairsdp(int n, vector<int>& dp) {
        if (n<2) return 1;
        if (dp[n]) return dp[n];
        else return dp[n] = climbStairsdp(n-1, dp) + climbStairsdp(n-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        return climbStairsdp(n, dp);
    }
};