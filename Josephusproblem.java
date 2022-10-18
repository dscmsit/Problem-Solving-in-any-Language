class Josephusproblem
{
    
   public int jos_fr_zero(int n, int k){
        if(n == 1){
            return 0;
        }
        
        
        int x = jos_fr_zero(n-1, k);
        int y = (x + k) % n;
        
        return y;
   }    
   public int josephus(int n, int k){
        return jos_fr_zero(n,k) + 1;
    }

}
