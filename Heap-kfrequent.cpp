#include <bits/stdc++.h>
using namespace std;
vector<int> frequentK(vector<int> &nums, int k)
{
    int size = nums.size();
    vector<int> ans;
    unordered_map<int, int> frequencyCount;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (int i = 0; i < size; i++)
    {
        frequencyCount[nums[i]]++;
    }
    for (auto i = frequencyCount.begin(); i != frequencyCount.end(); i++)
    { // first is the number[1,2,3,4] second is the count
        // as we want to sort according to count we push second first
        // as we have iterator we use arrow dot wont work
        minHeap.push({i->second, i->first});
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    while (!minHeap.empty())
    {
        // here the second is the min heap second denoting the maps first
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 1, 1, 3, 2, 2, 4};
    int k = 2;
    vector<int> ans = frequentK(nums, k);
    for (auto &it : ans)
    {
        cout << it << " ";
    }

    return 0;
}
