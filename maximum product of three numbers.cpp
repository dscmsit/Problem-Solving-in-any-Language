class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int smallest= INT_MAX, smaller = INT_MAX;
        int largest= INT_MIN, larger= INT_MIN, large= INT_MIN;
        for(int n: nums){
            if(n <= smallest){
                smaller= smallest;
                smallest =n;
            } 
            else if( n<= smaller){      //n is bw smaller and smallest
                smaller =n;
            }
            if(n>=largest){
                large   = larger;
                larger  = largest;
                largest =n;
            }
            else if(n>=larger){     // lies bw largest and larger
                large   = larger;
                larger  =n;
            }
            else if(n>=large){                   // lies bw larger and large
                large   = n;
            }
        }
        if(smallest*smaller*largest> large*larger*largest)
            return smallest*smaller*largest;
        else
            return large*larger*largest;
    }
};