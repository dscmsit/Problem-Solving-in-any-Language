#include <bits/stdc++.h>
using namespace std;

void stockSpan(vector<int> &nums)
{
    int size = nums.size();
    int result[size], greaterOnLeft[size];
    stack<int> st;

    for (int i = 0; i < size; i++)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            greaterOnLeft[i] = -1;
        }
        else
        {
            greaterOnLeft[i] = st.top();
        }
        st.push(i);
    }
    for (int i = 0; i < size; i++)
    {
        result[i] = i - greaterOnLeft[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    vector<int> nums = {100, 80, 60, 70, 60, 75, 85};
    stockSpan(nums);

    return 0;
}
