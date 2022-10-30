#include <iostream>
typedef long long int ll;
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    ll x, y;
	    cin>>x>>y;
	    if(x%2==1)
	        cout<<"NO\n";
	    else if(x==0 && y==0)
	        cout<<"NO\n";
	    else if(x==0 && y%2==1)
	        cout<<"NO\n";
	    else
	        cout<<"YES\n";
	}
	return 0;
}