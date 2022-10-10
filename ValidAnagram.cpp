class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        //std::cout<<n1;
        if(n1 != n2)
            return false;
        int S1[26] = {0};
        int S2[26] = {0};
        // unordered_map<char,int> S1;
        // unordered_map<char,int> S2;
        for(int i = 0; i < n1; i++)
        {
            S1[s[i] - 'a']++;
            S2[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(S1[i] != S2[i])
                return false;
        }
        return true;
    }
};
