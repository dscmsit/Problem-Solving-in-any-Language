class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //31412
        stack<int>s;
        int temp=INT_MIN;//-13206
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]<temp)//2<-13206
            {
                return true;
            }
            while(!s.empty() && nums[i]>s.top()) //2>-13206 yes
            {
                 temp=s.top();   //temp=2
                 s.pop(); 
            }
            s.push(nums[i]); //1
        }
        return false;
    }
};
