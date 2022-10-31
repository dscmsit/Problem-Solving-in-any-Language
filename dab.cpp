#include <iostream>
using namespace std;
 
int main()
{
    int n = 5;

    int row = 1;

    while(row<=n){
        int col_1 = 1;
        int col_2 = 1;

        int count = 1;

        while(col_1<=(n-row+1)){
            cout << count << " ";
            count++;
            col_1++;
        }

        
        int star_1 = row-1;
        while(star_1){
            cout << "*" << " ";
            star_1--;
        }
        int star_2 = row-1;
        while(star_2){
            cout << "*" << " ";
            star_2--;
        }


        int count_2 = n+col_2-1;
        
        while(col_2<=(n-row+1)){
            cout << count_2 << " ";
            count_2--;
            col_2++;
        }
        cout<< endl;
        row++;
    }
    return 0;
}
