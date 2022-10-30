class Solution {
public:

    void dfs(int sr,int sc,vector<vector<int>> &ans,vector<vector<int>>& image,int newcolor, int delrow[],int delcol[], int iniColor)
    {
        int n=image.size();
        int m=image[0].size();
        ans[sr][sc]=newcolor;
        for(int i=0;i<4;i++)
        {
               int nrow= sr+delrow[i];
               int ncol= sc+delcol[i];
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newcolor)
                dfs(nrow,ncol,ans,image,newcolor,delrow,delcol,iniColor);
            }
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int iniColor= image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        dfs(sr,sc,ans,image,color,delrow,delcol, iniColor);
        return ans;
    }
};
