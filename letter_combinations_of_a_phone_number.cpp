class Solution
{
public:
    void helper(int idx, vector<string> &ds, string s, vector<string> &ans)
    {
        if (idx == ds.size())
        {
            ans.push_back(s);
            return;
        }

        for (int i = 0; i < ds[idx].length(); i++)
        {
            s.push_back(ds[idx][i]);
            helper(idx + 1, ds, s, ans);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return {};
        vector<string> ds;
        for (char c : digits)
        {
            if (c == '2')
                ds.push_back("abc");
            if (c == '3')
                ds.push_back("def");
            if (c == '4')
                ds.push_back("ghi");
            if (c == '5')
                ds.push_back("jkl");
            if (c == '6')
                ds.push_back("mno");
            if (c == '7')
                ds.push_back("pqrs");
            if (c == '8')
                ds.push_back("tuv");
            if (c == '9')
                ds.push_back("wxyz");
        }
        string s;
        vector<string> ans;
        helper(0, ds, s, ans);
        return ans;
    }
};