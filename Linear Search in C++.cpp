#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n;
	cin >> n;
	int flag = 0;
	for (int i = 0; i < 9; i++)
	{
		if (arr[i] == n)
		{
			flag = 1;
			break;
		}
	}
	if (flag){
		cout << "Your Number is Found in the Array\n";
	}
	else{
		cout << "Your Number is not Found in the Array\n";
	}
	return 0;
}
