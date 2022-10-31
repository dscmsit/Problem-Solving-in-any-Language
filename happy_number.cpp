class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while(n!=1){
            if(visited.find(n)!= visited.end())
                return false;
            else{
                visited.insert(n);
                int temp =0;
                while(n){
                    int digit = n%10;
                    temp+=(digit * digit);
                    n/=10;
                }
                n=temp;
            }
        }
        return true;
    }
};