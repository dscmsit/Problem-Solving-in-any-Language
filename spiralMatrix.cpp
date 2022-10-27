#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep(int, i, z) for (int i = 0; i < z; i++)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int left=0,right=matrix[0].size()-1, top=0, bottom = matrix.size()-1;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
               for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (top > bottom) break;
            
               for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
              bottom--;
             if(left>right)break;
          
              for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
           
            
        }
        return ans;
    }
};
