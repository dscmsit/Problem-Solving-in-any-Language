// 51. Leetcode {HARD} [Backtracking, Recursion]

#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    bool isSafe(int row, int col, vector<string> &grid, int n)
    {

        // check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (grid[i][col] == 'Q')
                return false;

        // check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (grid[i][j] == 'Q')
                return false;

        // check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (grid[i][j] == 'Q')
                return false;

        return true;
    }

public:
    void solve(int row, vector<string> &grid, vector<vector<string>> &ans, int n)
    {
        // BASE COND'N
        if (row == n)
        {
            ans.push_back(grid);
            return;
        }

        for (int col = 0; col < n; col++)
        {

            if (isSafe(row, col, grid, n))
            {

                grid[row][col] = 'Q';
                solve(row + 1, grid, ans, n);
                grid[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {

        vector<vector<string>> ans;
        vector<string> grid(n, string(n, '.'));
        // string s(n,'.')

        solve(0, grid, ans, n);

        return ans;
    }
};