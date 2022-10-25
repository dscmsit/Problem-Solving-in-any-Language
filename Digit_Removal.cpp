#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long long int te;
	cin>>te;
	while(te--)
	{
	    long long int n;
	    int d, di=0;
	    cin>>n>>d;
	    long long int t=n;
	    while(t>0)
	    {
	        t/=10;
	        di++;
	    }
	    t=n;
	    long long int sum=0, alt_sum=0;
	    if(d!=0)
	    {
	        for(int i=0; i<di; i++)
	        {   
	            int r=t%10;
	            alt_sum+=r*pow(10, i);
	            if(r==d)
	            {
	               sum+=(r+1)*pow(10, i)-alt_sum;
	               t*=10;
	               t+=10;
	               alt_sum=0;
	               i--;
	            }	            	        
	            t/=10;
	        }
	    }
	    else
	    {
	        int temp=0, t=n, i=0;
	        while(t>0)
	        {
	            int in=t%10;
	            if(in==0)
	            {
	                int sp=0;
	                for(int j=i-1; j>=0; j--)
	                    sp+=pow(10, j);
	                temp=sp;
	                temp+=1*pow(10, i);
	            }
	            else
	            {
	                temp+=in*pow(10, i);
	            }
	            i++;
	            t/=10;
	        }
	        sum=temp-n;
	    }
	    cout<<sum<<endl;
	}
	return 0;
}