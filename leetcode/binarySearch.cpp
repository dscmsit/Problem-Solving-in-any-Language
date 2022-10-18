#include <bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int n, int k) {
   // code here
   int l = 0;
   int h = n - 1;
   while (l <= h) {
      int mid = l + (h - l) / 2;
      if (arr[mid] == k)
         return mid;
      else if (k < arr[mid]) h = mid - 1;
      else l = mid + 1;
   }
   return -1;
}

int main() {

   int N;
   cin >> N;
   int arr[N];
   for (int i = 0; i < N; i++) cin >> arr[i];
   int key;
   cin >> key;
   int found = binarysearch(arr, N, key);
   cout << found << endl;
}
