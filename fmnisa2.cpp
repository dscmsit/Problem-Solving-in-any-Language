#include<bits/stdc++.h>
using namespace std;
int missingno(int a[],int n){
    int i,total =1;

    for (int i=2 ;i<(n+1);i++){
    total +=i;
    total -=a[i-2];
    }
    return total;
    
}

int main()
{
    int arr[]={1,2,3,5};
    int N = sizeof(arr)/sizeof(arr[0]);

    int miss =missingno(arr,N);
    cout<<miss;
    return 0;

}