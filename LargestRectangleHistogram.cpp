// 84. Leetcode {HARD}  [Arrays, Stack]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;

        for (int i = 0; i <= n; i++)
        {
            int currHeight = i == n ? 0 : heights[i];
            // check if currHeight becomes greater then height[top] element of stack. we do a push because it's an increasing sequence
            // otherwise we do pop and find area, so for that we write a while loop
            while (!st.empty() && currHeight < heights[st.top()])
            {
                int top = st.top();
                st.pop(); // current element on which we are working
                // now we need width & area
                int width = st.empty() ? i : i - st.top() - 1; // width differ if we stack is empty or not empty after we pop the element
                int area = heights[top] * width;               // current height * width
                maxArea = max(area, maxArea);
            }
            st.push(i);
        }
        return maxArea;
    }
};