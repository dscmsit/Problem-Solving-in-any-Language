class Solution {
public:
    int v;
    void dfs(int node, vector<int> &vis,vector < int > list1[])
    {
        vis[node]=1;
        for(auto it: list1[node])
        {
            if(!vis[it])
                dfs(it, vis, list1);
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int v =isConnected.size();
        vector<int>vis(v,0);
        vector<int> list1[v];

        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    list1[i].push_back(j);
                    list1[j].push_back(i);
                }
            }
        }

        int c=0;
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(i, vis, list1);
            }
        }
        return c;

    }
};
