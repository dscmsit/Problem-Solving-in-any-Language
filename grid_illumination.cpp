class Solution
{
public:
    int N;
    unordered_map<int, int> r, c, dl, dr;
    set<pair<int, int>> s;

    void helper(int i, int j)
    {
        if (!(i < N && j < N && i >= 0 && j >= 0))
            return;

        if (s.find({i, j}) != s.end())
        {
            s.erase({i, j});
            r[i]--;
            c[j]--;
            dl[i + j]--;
            dr[i - j]--;
        }
    }

    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        N = n;

        for (int i = 0; i < lamps.size(); i++)
        {
            if (s.find({lamps[i][0], lamps[i][1]}) == s.end())
            {
                s.insert({lamps[i][0], lamps[i][1]});
                r[lamps[i][0]]++;
                c[lamps[i][1]]++;
                dl[lamps[i][0] + lamps[i][1]]++;
                dr[lamps[i][0] - lamps[i][1]]++;
            }
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            int rq = queries[i][0];
            int cq = queries[i][1];
            if (s.find({rq, cq}) != s.end() || r[rq] || c[cq] || dl[rq + cq] || dr[rq - cq])
            {
                ans.push_back(1);
            }
            else
                ans.push_back(0);

            helper(rq, cq);
            helper(rq + 1, cq);
            helper(rq - 1, cq);
            helper(rq, cq + 1);
            helper(rq, cq - 1);
            helper(rq + 1, cq + 1);
            helper(rq - 1, cq + 1);
            helper(rq + 1, cq - 1);
            helper(rq - 1, cq - 1);
        }
        return ans;
    }
};