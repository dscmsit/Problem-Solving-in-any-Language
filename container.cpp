#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep(int, i, z) for (int i = 0; i < z; i++)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int l=0;
        int n=height.size()-1;
        while(n>l){
            res=max(res,min(height[l],height[n])*(n-l));
            if(height[l]<height[n]){
                l++;
            }
            else if(height[l]>height[n]){
                n--;
            }
            else {
                n--;
                l++;
            }
        }
        return res;
    }
};
