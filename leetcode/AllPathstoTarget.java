class AllPathsToTarget {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        Graph G = new Graph(graph.length);
        for (int i=0;i<graph.length;i++)
        {
            for (int j=0;j<graph[i].length;j++)
            {
                G.addEdge(i,graph[i][j]);
            }
        }
        List<List<Integer>> ans = new ArrayList<>();
        int source = 0;
        ArrayList<Integer> temp = new ArrayList<>();
        temp.add(0);
        dfs(source,graph,ans,temp);
        return ans;
        
    }
    public void dfs(int start, int[][] graph, List<List<Integer>> l, ArrayList<Integer> path)
    {
        if (start==graph.length-1)
        {
            l.add(new ArrayList<>(path));
            return ;
        }
        
        for (int i=0;i<graph[start].length;i++)
        {
            path.add(graph[start][i]);
            dfs(graph[start][i],graph,l,path);
            path.remove(path.size()-1);
        }
    }
}
class Graph
{
    public int V;
    public boolean[] visited;
    public ArrayList<ArrayList<Integer>> adj;
 
    // Constructor
    public Graph(int v)
    {
        V = v;
        visited = new boolean[V];
        adj = new ArrayList<>();
        for (int i=0; i<v; ++i)
            adj.add(new ArrayList<>());
    }
 
    // Function to add an edge into the graph
    public void addEdge(int v,int w)
    {
        adj.get(v).add(w);
    }
 
    public void BFS(int s)
    {
        LinkedList<Integer> queue = new LinkedList<Integer>();
        visited[s]=true;
        queue.add(s);
 
        while (queue.size() != 0)
        {
            s = queue.poll();
            Iterator<Integer> i = adj.get(s).listIterator();
            while (i.hasNext())
            {
                int n = i.next();
                if (!visited[n])
                {
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }
    }
}