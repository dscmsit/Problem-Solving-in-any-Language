#include <bits/stdc++.h>
using namespace std;
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// Time: 2n insertions and 2n deletions
// Since in deque, push_back() and push_front() are O(N) OPERATIONS
// TIME: O(n)
void printKMax(int arr[], int n, int k)
{
    deque<int> dq;

    // For every element, the previous smaller elements are useless so remove them from dq
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (int i = k; i < n; i++)
    {
        // The element at the front of the queue is the largest element of previous window, so print it
        cout << dq.front() << " ";

        // Remove the elements which are out of this window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        //  Remove all elements smaller than the currently being added element (remove useless elements)
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        // Add current element at the rear of dq
        dq.push_back(i);
    }
    // Print the maximum element of last window
    cout << dq.front() << " ";
}
int main()
{
    FIO

        return 0;
}
