class Solution {
public:
    int solve(int n, int k){
        if(n == 1){
            return 0;
        }
        
        int ans = (solve(n-1, k)+k) % n;
        return ans;
    }
    
    int findTheWinner(int n, int k) {
        int ans = solve(n,k) + 1;
        return ans;
    }
};
