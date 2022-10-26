#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep(int, i, z) for (int i = 0; i < z; i++)
class Solution {
public:
    int divide(int dividend, int divisor) {
         if(dividend == INT_MIN && divisor == -1)return INT_MAX;
        long ans = 0;
        
        int sign = 1;
        if(divisor < 0)sign*=-1;
        if(dividend <0)sign*=-1;
        
        long dend=labs(dividend);
        long sor=labs(divisor);
        
        while(sor <= dend){
            long temp=sor;
            long pow=1;
            while(temp+temp<dend){
                temp+=temp;
                pow+=pow;
            }
            ans+=pow;
            dend-=temp;
        }
        return ans*sign;
    }
};