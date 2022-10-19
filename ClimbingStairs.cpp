class Solution {
public:
    int climbStairs(int n)
    {
        vector<int> ans;
        int term1 = 0;
        int term2 = 1;
        ans.push_back(term1);
        ans.push_back(term2);
        int term3 = term1 + term2;
        ans.push_back(term3);
        if(n == 1)
            return term3;
        else
        {
            int i = 3;
            while(i < (n+2))
            {
                term1 = term2;
                term2 = term3;
                term3 = term1 + term2;
                ans.push_back(term3);  
                i++;
            }
            return ans[ans.size()-1];
        }
    }
};