class Solution {
public:
    bool isValid(string expression) {
        stack<char>s;
        for(int i=0;i<expression.length();i++){
            char ch = expression[i];
        //opening parantheses push
           if(ch=='(' || ch=='{' || ch=='[')
           {
              s.push(ch);

           }
        //for close parantheses check on top and pop
        else
        {
            if(!s.empty()) {
                char top=s.top();


            if( ch==')' && top=='('
               ||
              ch=='}' && top=='{'
               ||
              ch==']' && top=='[')  
            {
                s.pop();
}
            else 
            {
                return false;
}
        }
else {
return false;
}
            
            
            }
               

        
        }
if(s.empty())
    return true;

    
else 
    return false;
    }
};