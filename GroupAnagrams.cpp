// 49. Leetcode  {MEDIUM}  [Arrays, Hashmap]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        unordered_map<string, vector<string>> m;

        for (int i = 0; i != strs.size(); i++)
        {

            string temp = strs[i];

            sort(temp.begin(), temp.end());

            m[temp].push_back(strs[i]);
        }

        vector<vector<string>> sol;

        for (auto itr = m.begin(); itr != m.end(); itr++)
        {

            sol.push_back(itr->second);
        }

        return sol;
    }
};