class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows < cols || rows > cols)
        {
            for(int i = 0; i < cols; i++)
            {
                vector<int> ans2;
                for(int j = 0; j < rows; j++)
                {
                    ans2.push_back(matrix[j][i]);                    
                }
                ans.push_back(ans2);
            }
            return ans;
        }
        else
        {
            for(int i = 0; i < rows; i++)
            {
                vector<int> ans2;
                for(int j = 0; j < cols; j++)
                {                
                    ans2.push_back(matrix[j][i]);
                }
                ans.push_back(ans2);
            }
            return ans;
        }
    }
};
