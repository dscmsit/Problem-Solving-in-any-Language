
#include <iostream>

using namespace std;
int floorSqrt(int x)
{
    // Base cases
    if (x == 0 || x == 1)
        return x;

    // Do Binary Search for floor(sqrt(x))
    int start = 1, end = x / 2, ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        // If x is a perfect square
        int sqr = mid * mid;
        if (sqr == x)
            return mid;

        // Since we need floor, we update answer when
        // mid*mid is smaller than x, and move closer to
        // sqrt(x)

        /*
           if(mid*mid<=x)
                   {
                           start = mid+1;
                           ans = mid;
                   }
            Here basically if we multiply mid with itself so
           there will be integer overflow which will throw
           tle for larger input so to overcome this
           situation we can use long or we can just divide
            the number by mid which is same as checking
           mid*mid < x

           */
        if (sqr <= x)
        {
            start = mid + 1;
            ans = mid;
        }
        else // If mid*mid is greater than x
            end = mid - 1;
    }
    return ans;
}

// Driver program
int main()
{
    int x = 11;
    cout << floorSqrt(x) << endl;
    return 0;
}