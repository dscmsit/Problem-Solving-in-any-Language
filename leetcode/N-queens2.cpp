// 52. Leetcode [Backtracking, Recursion]

#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    bool isSafe(int row, int col, vector<vector<bool>> &grid, int n)
    {

        // check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (grid[i][col] == 1)
                return false;

        // check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (grid[i][j] == 1)
                return false;

        // check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (grid[i][j] == 1)
                return false;

        return true;
    }

public:
    int solve(int row, vector<vector<bool>> &grid, int n)
    {
        // BASE COND'N
        if (row == n)
        {
            return 1;
        }
        int count = 0;
        for (int col = 0; col < n; col++)
        {

            if (isSafe(row, col, grid, n))
            {

                grid[row][col] = 1;
                count += solve(row + 1, grid, n);
                grid[row][col] = 0;
            }
        }

        return count;
    }

public:
    int totalNQueens(int n)
    {

        vector<vector<bool>> grid(n, vector<bool>(n, 0));
        return solve(0, grid, n);
    }
};