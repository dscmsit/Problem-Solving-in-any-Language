// 218. The Skyline Problem 
// Ques Topic : Ordered Set, Hashmaps and Heaps, Sorting.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // use walls to record buildings; left x is an insertion event, and right x is a deletion event
        vector<pair<int, int>>xaxis; // first: x, second: height
        vector<vector<int>>ans;                 
        for (auto b : buildings) {
            // let left x has negative height to ensure left x goes to multiset first if with same 'x' as right x // add before removing is imp in case of same right x of one building and left x of other building
            xaxis.push_back(make_pair(b[0], -b[2]));
            xaxis.push_back(make_pair(b[1], b[2]));
        }
        sort(xaxis.begin(), xaxis.end());                   // sort walls
        multiset<int>leftxHeights = {0};// keep left x heights sorted; dummy'0'for convenience
        int mhabtpi = 0;     // current max height among leftxHeights
        for (auto xh : xaxis) {
            if (xh.second < 0) {   // it's a left x, insert the height
                leftxHeights.insert(-xh.second);
            } 
            else {   // it's a right x, delete the height
                leftxHeights.erase(leftxHeights.find(xh.second));
            }
            
            if (*leftxHeights.rbegin() != mhabtpi) {  // mark a skyline point
                ans.push_back({xh.first,mhabtpi = *leftxHeights.rbegin()});
            }
        }
        return ans; 
    }
};