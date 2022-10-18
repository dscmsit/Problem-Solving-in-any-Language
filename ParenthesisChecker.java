
class Solution
{
    //Function to check if brackets are balanced or not.
    static boolean ispar(String x)
    {
        ArrayDeque<Character> stack = new ArrayDeque<>();
        for(int i = 0; i < x.length(); i++){
            if(x.charAt(i) == '{' || x.charAt(i) == '(' || x.charAt(i) == '['){
                stack.push(x.charAt(i));
            }
            else{
                if(stack.isEmpty()){
                    return false;
                }
                
                else if(x.charAt(i) == '}'){
                    if(stack.peek() == '{'){
                        stack.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(x.charAt(i) == ')'){
                    if(stack.peek() == '('){
                        stack.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(x.charAt(i) == ']'){
                    if(stack.peek() == '['){
                        stack.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(stack.isEmpty() == false){
            return false;
        }
        else{
            return true;
        }
    }
}
