#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep(int, i, z) for (int i = 0; i < z; i++)

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int l = 31;
        int r = 0;
        uint32_t result = 0;
        while(l>r)
        {
            if( ((n & 1<<l) ^ (n & 1<<r)) != 0)
            {
                uint32_t t = (n & 1<<r)<<(l-r);
                
                result |= (n & 1<<l)>>(l-r);
                result |= t;
            }
            l--;
            r++;
        }
        
        return result;
    }
};