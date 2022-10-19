class Solution
{
public:
    // bfs solution
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 2)
            return 0;

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);

        vector<bool> visited(n);
        visited[0] = true;

        int jumps = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int curr = q.front();
                q.pop();
                if (curr == n - 1)
                    return jumps; // reached to last index
                vector<int> &next = mp[arr[curr]];
                next.push_back(curr - 1);
                next.push_back(curr + 1);
                for (int j : next)
                {
                    if (j >= 0 && j < n && visited[j] == 0)
                    {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear(); // avoid later lookup mp arr[i]
            }
            jumps++;
        }

        return 0;
    }
};