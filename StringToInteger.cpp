class Solution {
public:
    int myAtoi(string s)
    {
            long long int n=s.size();
             long long   int i=0,ans=0,pos=1;
        while(i<n && s[i]==' ') ++i;
        if(i<n && (s[i]=='+' || s[i]=='-')) {
            if(s[i]=='-') pos=-1;
            ++i;
        }
        while(i<n && (s[i]>='0' && s[i]<='9')){
            ans*=10;
            ans+=int(s[i]-'0');
            ++i;
            if(ans*pos>INT_MAX) return INT_MAX;
            if(ans*pos<INT_MIN) return INT_MIN;
        }
        ans*=pos;
        return ans;
    }
        
    
};
