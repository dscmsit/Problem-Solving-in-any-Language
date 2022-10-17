#define psi pair<int, string>
class myComparator
{
public:
    bool operator()(psi &p1, psi &p2)
    { // first denotes freq, second denotes lexicograph
        if (p1.first == p2.first)
            return p1.second > p2.second; // although it should be < sign but in priority queue comparator sign reverses as taught by sarthak bhaiya

        return p1.first < p2.first; // although it should be > sign but in priority queue comparator sign reverses as taught by sarthak bhaiya
    }
};
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        for (auto it : words)
            mp[it]++;

        priority_queue<psi, vector<psi>, myComparator> pq;
        for (auto it : mp)
            pq.push(make_pair(it.second, it.first));

        vector<string> ans;
        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};