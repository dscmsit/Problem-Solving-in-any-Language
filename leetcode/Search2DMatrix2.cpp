// 240. Leetcode {MEDIUM}  [Binary Search , Array , Matrix]

#include <bits/stdc++.h>
using namespace std;

// Used the property of sorted matrix order for carrying out the searching of elements!
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0, j = m - 1;

        while (i < n && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            if (matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};