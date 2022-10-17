class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < routes.size(); i++)
        {
            for (int it : routes[i])
            {
                mp[it].push_back(i); // for a particular stop we are making a vector of buses
            }
        }

        queue<pair<int, int>> bfs;
        bfs.push({source, 0});

        unordered_set<int> seen = {source};

        while (!bfs.empty())
        {
            int stop = bfs.front().first, bus = bfs.front().second;
            bfs.pop();

            if (stop == target)
                return bus;

            for (int i : mp[stop])
            {
                for (int j : routes[i])
                {
                    if (seen.find(j) == seen.end())
                    {
                        seen.insert(j);
                        bfs.push({j, bus + 1});
                    }
                }
                routes[i].clear(); // no need to check that route again
            }
        }
        return -1;
    }
};