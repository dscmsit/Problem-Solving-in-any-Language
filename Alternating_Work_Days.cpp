#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int a, b, p, q;
	    cin>>a>>b>>p>>q;
	    if((p%a==0) && (q%b==0))
	    {
	        long long int d1=p/a;
	        long long int d2=q/b;
	        if(d1-d2==1 || d1-d2==-1 || d1==d2)
	            cout<<"YES\n";
	        else
	            cout<<"NO\n";
	    }
	    else
	        cout<<"NO\n";
	}
	return 0;
}