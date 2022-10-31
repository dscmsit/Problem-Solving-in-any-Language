void nextPermutation(vector<int>& nums) 
    {
        int n=nums.size();
        int l,r;
        for(l=n-2;l>=0;l--)                           // find decreasing sequence
        {
            if(nums[l]<nums[l+1]) break;
        }
        if(l<0) reverse(nums.begin(),nums.end());
        else
        {
            for(r=n-1;r>l;r--)                       // find rightmost successor to pivot
            {
                if(nums[r]>nums[l]) break;
            }
            swap(nums[l],nums[r]);                  // swap l,r
            
            reverse(nums.begin()+l+1,nums.end());   // reverse from l+1 to end
        }
    }