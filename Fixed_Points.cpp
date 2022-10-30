#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n, sum=0;
	    cin>>n;
	    int arr[n+1];
	    for(int i=1; i<=n; i++)
	    {
	        cin>>arr[i];
	        if(arr[i]<=i)
	        {
	            sum+=(n-i+1);
	        }
	    }
	    cout<<sum<<endl;
	}
	return 0;
}