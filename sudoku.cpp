#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep(int, i, z) for (int i = 0; i < z; i++)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int>rowi[9];
        unordered_map<char,int>coli[9];
        unordered_map<char,int>boxi[9];
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char a = board[i][j];
                if(a!='.' && (rowi[i][a]++ > 0 || coli[j][a]++ > 0 || boxi[i/3*3 + j/3][a]++ > 0)){
                    return false;
                }
            }
        }
        return true;
    }
};