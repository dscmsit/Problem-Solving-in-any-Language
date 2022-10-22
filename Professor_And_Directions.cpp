#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long int n; 
	    cin>>n;
	    char instructions[n+1];
	    cin>>instructions;
	    long int i=0;
	    for(i; i<n-1; i++)
	    {
	        if(instructions[i]==instructions[i+1])
	        {
	            cout<<"YES\n";
	            break;
	        }
	    }
	    if(instructions[i]!=instructions[i+1])
	        cout<<"NO\n";
	}
	return 0;
}