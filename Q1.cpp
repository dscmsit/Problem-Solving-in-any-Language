#include <iostream>
using namespace std;
 
int main()
{
    int n = 4;

    int row = 1;

    while(row<=n){
        int col = 1;
        int count= row;
        while(col<=row){
            char value = 'A' + count -1;
            cout << value << " ";
            count++;
            col++;
        } 
        cout << endl;
        row++;
    }
    return 0;
}
