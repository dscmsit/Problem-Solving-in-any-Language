class Solution {
public:
    set<vector<int>> pu(vector<int>nums)
    {
        if(nums.size()==1)
        {
              vector<int>v;
               v.push_back(nums[0]);
             set<vector<int>>ans;
                  ans.insert(v);
            return ans;
        }
        vector<int>v;
        for(int i=1;i<nums.size();i++)
        {
            v.push_back(nums[i]);
        }
       set<vector<int>>s= pu(v);
        set<vector<int>>ans;
        int i=0;
        for(auto val:s){
          //val is a vector
            
            vector<int>vale;
            vale.push_back(nums[0]);
            for(auto valr:val){vale.push_back(valr);}
            ans.insert(vale);
            for(int i=0;i<vale.size()-1;i++)
            {
                int a=vale[i];
                int b=vale[i+1];
                int temp=a;
                a=b;
                b=temp;
                vale[i]=a;
                vale[i+ 1]=b;
                ans.insert(vale);
                
            }
     }
        return ans;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>>v;
        set<vector<int>>ans=pu(nums);
        for(auto val:ans)
        {
            v.push_back(val);
        }
        return v;
        
    }
};