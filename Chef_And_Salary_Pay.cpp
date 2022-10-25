#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int x, y, days=0, streak=0, count=0;
	    char schedule[31];
	    cin>>x>>y;
	    cin>>schedule;
	    for(int i=0; i<30; i++)
	    {
	        if(schedule[i]=='1')
	        {
	            count++;
	            days++;
	            if(schedule[i+1]=='0'||schedule[i+1]=='\0')
	            {
	                if(count>streak)
	                {
	                    streak=count;
	                }
	                count=0;
	            }
	        }
	    }
	    int salary=x*days;
	    int bonus=y*streak;
	    int total=salary+bonus;
	    cout<<total<<endl;
	}
	return 0;
}