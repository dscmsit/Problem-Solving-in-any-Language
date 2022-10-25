class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        vector<int> v;
        int leng;
        vector<vector<int>> ans;
        for (auto it : wall)
        {
            int sum = 0;
            for (auto i : it)
            {
                sum += i;
                v.push_back(sum);
            }
            ans.push_back(v);
            v.clear();
            leng = sum;
        }
        for (auto it : ans)
        {
            for (auto i : it)
            {
                cout << i << " ";
            }
        }
        unordered_map<int, int> m;
        int maxx = 0;
        for (auto it : ans)
        {
            for (auto i : it)
            {
                if (i == leng)
                    continue;
                if (m.find(i) == m.end())
                {
                    m[i] = 1;
                }
                else
                    m[i]++;
                maxx = max(maxx, m[i]);
            }
        }

        return wall.size() - maxx;
    }
};