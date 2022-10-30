//              Power of two
//Given an integer n, return true if it is a power of two. Otherwise, return false.
//An integer n is a power of two, if there exists an integer x such that n == 2^x.

#include <iostream>
using namespace std;
bool isPowerOfTwo(int n) {
        int bits=0;
        while(n){
            if((n&1)==1 ) 
            {
                bits++;
                if(bits>1) return 0;                
            }
            n=n>>1;
        }
        if(bits==1)
            return 1;
        return 0;
    }
int main() {
    int n;
    cin >> n;
    cout << isPowerOfTwo(n);
    return 0;