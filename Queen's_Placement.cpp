#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    for(int i=1; i<=n; i++)
	    {
	        for(int j=1; j<=n; j++)
	        {
	            if(j==n-i+1 && j!=3 && j!=1)
	                cout<<"Q";
	            else if(i==n-1 && j==2)
	                cout<<"Q";
	            else
	                cout<<".";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}