class Solution {
public:
    
     vector<string> lcp(string s){
        
         if(s.size()==1)
         {
             if(isalpha(s[0]))
             {
                 char ch;
                 vector<string>ans;
                 if(islower(s[0])){
                  ch=toupper(s[0]);
                 }else{
                        ch=tolower(s[0]);
                 }
                 string f(1,s[0]);
                   string fr(1,ch);
                 ans.push_back(f);
                 ans.push_back(fr);
                 return ans;
             }
             else
             {
                   vector<string>ans;
                   string f(1,s[0]);
                  ans.push_back(f);
                 return ans;
             }
         }
         string str;
         for(int i=1;i<s.size();i++)
         {
             str.push_back(s[i]);
         }
         vector<string>v=lcp(str);
         char c=s[0];
          vector<string>ans;
         if(isalpha(c)){
             for(auto val:v)
             {
                string f(1,c);
                 ans.push_back(f+val);
             }
             char ch;
             if(islower(s[0])){
                  ch=toupper(s[0]);
                 }else{
                        ch=tolower(s[0]);
                 }
               for(auto val:v)
             {
                string f(1,ch);
                 ans.push_back(ch+val);
             }
             return ans;
         }
         else
         {
               for(auto val:v)
             {
                string f(1,c);
                 ans.push_back(f+val);
             }
             return ans;
         }
    }
    vector<string> letterCasePermutation(string s) {
       vector<string>ans=lcp(s);
        
        return ans;
        
    }
};