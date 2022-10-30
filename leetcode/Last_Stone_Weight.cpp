class Solution {
public:
    int lastStoneWeight(vector<int>& s)
    {
        priority_queue<int> q(s.begin(),s.end());
        while(q.size()>1)
        {
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            if(a!=b)
                q.push(a-b);

        }

        if(q.empty())
            return 0;
        return q.top();
    }
};
