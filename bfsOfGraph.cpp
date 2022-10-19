  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> bfs;
        vector<int> vis(V,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
       
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
           
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
       return bfs;
    }
};
