class Solution
{
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> mp;
        for (auto it : s)
            mp[it]++;

        string ans = "";
        priority_queue<pair<int, char>> pq;
        for (auto it : mp)
            pq.push(make_pair(it.second, it.first));

        while (pq.size() > 1)
        {
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();

            ans += top1.second;
            ans += top2.second;

            top1.first--;
            top2.first--;

            if (top1.first > 0)
                pq.push(top1);
            if (top2.first > 0)
                pq.push(top2);
        }

        if (!pq.empty())
        {
            if (pq.top().first > 1)
                return "";
            else
                ans += pq.top().second;
        }
        return ans;
    }
};