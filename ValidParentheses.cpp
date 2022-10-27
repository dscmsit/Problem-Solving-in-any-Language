class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2==0)
        {
            stack <char> st;
            st.push('#');
            for(int i=0;i<s.length();i++){
                if(s[i]=='(' || s[i]=='{'||s[i]=='[')
                st.push(s[i]);
                else
                {
                    char top = st.top();
                    if((s[i]==')'&& top=='(')||(s[i]=='}'&& top=='{')||(s[i]==']'&& top=='['))
                    st.pop();
                    else
                        return false;
                }
            }
            return (st.top()=='#');
            
        }
        return false;
    }
};