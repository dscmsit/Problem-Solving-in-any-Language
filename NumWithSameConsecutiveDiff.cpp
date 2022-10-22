//Leetcode-967[Medium]

class Solution {
public:  
    
    void dfs(int i,int n, int k, vector<int> &output){
        if(n==1){
            output.push_back(i);
            return;
        }
        
        int dig=i%10;
      if(dig+k<10)
          dfs(i*10+dig+k, n-1, k ,output);
      
        if(k!=0 && dig>=k)
            dfs(i*10+dig-k ,n-1 ,k, output);      
        
    } 
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> output;
        // if(n==1){
        //     output.push_back(0);
        // }
            for(auto i=1;i<10;++i)
                dfs(i, n, k, output);
        return output;
    }
};