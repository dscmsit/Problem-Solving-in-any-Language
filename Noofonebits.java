public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int N) {
        int ans=0;
        while(N!=0){
            int msk=N & -N;
            N=N-msk;
            ans++;
        }
        return ans;
    }
}
