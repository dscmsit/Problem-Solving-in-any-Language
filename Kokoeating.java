class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int l=1;
        int hi=0;
        for(int i=0;i<piles.length;i++){
            hi=Math.max(hi,piles[i]);
        }
        int ans=Integer.MAX_VALUE;
        while(l<=hi){
            int mid=hi+(l-hi)/2;
            int hrs=0;
            for(int i=0;i<piles.length;i++){
                hrs+=piles[i]/mid;
                hrs+=piles[i]%mid>0?1:0;
            }
            if(hrs>h){
                l=mid+1;
            }
            else{
                hi=mid-1;
                ans=Math.min(ans,mid);
            }
        }
        return ans;
        
    }
}
