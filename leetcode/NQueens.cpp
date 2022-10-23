// N Queens Problem - Leetcode
// https://leetcode.com/problems/n-queens/
class Solution
{
public:
    bool isSafe(int n, int row, int col, vector<string> board)
    {
        int dr = row;
        int dc = col;
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }
        col = dc;
        row = dr;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            col--;
        }
        row = dr;
        col = dc;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row++;
            col--;
        }

        return true;
    }
    void solve(int n, int col, vector<string> &board, vector<vector<string>> &ans)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(n, row, col, board))
            {
                board[row][col] = 'Q';

                solve(n, col + 1, board, ans);

                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        solve(n, 0, board, ans);

        return ans;
    }
};