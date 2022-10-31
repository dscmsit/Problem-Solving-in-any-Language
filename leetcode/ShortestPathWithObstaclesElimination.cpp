/* 1293. Shortest Path in a Grid with Obstacles Elimination
Hard */
/* You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.
Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. 
If it is not possible to find such walk return -1. */
/*  Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2). */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 4 directions 
    const int dx[4] = { -1, 0, 0, 1 }, dy[4] = { 0, -1, 1, 0 };
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), steps = 0;
        vector<vector<int>> remains(m, vector<int>(n, INT_MIN));
        // as remains can go upto min of 0 thats why taken a val<0 in matrix initially
        // we have a queue storing {x, y, r} 
        // where x and y are coordinate and r is remain number of obstacles you can remove
        queue<array<int, 3>> q;
        // we start at (0, 0) with k
        q.push({0, 0, k});
        // at the beginning, you can eliminate at most k obstacles
        remains[0][0] = k;
        // BFS
        while (!q.empty()) {
            int lsz=q.size();
            while(lsz--) {
                auto cur = q.front(); q.pop();
               // if we reach the lower right corner (m - 1, n - 1) ,then return the minimum number of steps
                if (cur[0] == m - 1 && cur[1] == n - 1) return steps;
                // otherwise we can try 4 directions (up, down, left and right)
                for (int i = 0; i < 4; i++) {
                    // given we have at (x, y), we can move to (next_x, next_y)
                    int next_x = cur[0] + dx[i], next_y = cur[1] + dy[i];
                    // however, first we need to make sure (next_x, next_y) is within the grid
                    if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) 
                        continue; // nothing to do
            // then,we check if we can eliminate an obst and move there on this cell{nx,ny}
                    int remain = cur[2] - grid[next_x][next_y];// grid[nx][ny]=1 if obst
// we can only do that when `remain` is greater or equal to 0, as we can not elim {nx,ny} obst and continue further
// And the target remaining k must be less than the current remaining k
// remains[next_x][next_y] < remain denotes that on our curr path we have more rem obs left to rem further (greater possibility to reach destn) than the prev path to nx,ny (with smaller left rem obs to rem) 
// Doing all this in a min steps BFS sequence thus finding min steps ans with at most k obs 
                    if(remain >= 0 && remains[next_x][next_y] < remain) { 
                        // maintaining min obstacle remainning path within min steps 
                        // push to the queue for further process
                        q.push({next_x, next_y, remain});
                        // update the remaining k
                        remains[next_x][next_y] = remain;
                    }
                }
            }
            // increase step count
            steps += 1;
        }
        // if we reach here, 
        // then it means it is not possible to find such walk 
        return -1;
    }
};