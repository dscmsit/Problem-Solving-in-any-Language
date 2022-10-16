// https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1
/*

Q. The tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs N. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.
Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered N. Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc. Refer the provided link to get a better clarity about the puzzle.


Example 1:

Input:
N = 2
Output:
move disk 1 from rod 1 to rod 2
move disk 2 from rod 1 to rod 3
move disk 1 from rod 2 to rod 3
3
Explanation: For N=2 , steps will be
as follows in the example and total
3 steps will be taken.




Solution Approach : Recursion:


# Tower Of Hanoi :
    towerOfHanoi(int n,char src,char help,char dest);

## Example Problem :
*n=4*

---
FOR EVERY N :
--
- N - 1 disks from SRC to HELP ROD
    { towerOfHanoi(n-1,src,dest,help); }
- Move Nth disk to from SRC to DEST. ROD
- N - 1 disks from HELP to DEST. ROD

    { towerOfHanoi(n-1,help,src,dest); }

---
Base Condition :
--
n==1
    Move 1st from src to dest


---
# Code
    (4,A,B,C)
    {
        (3,A,C,B){
            (2,A,B,C){
                (1,A,C,B){
                    Move 1st From A to B
                }
                Move 2nd from A to C
                (1,B,A,C){
                    Move 1st from B to C
                }
            }
            Move 3rd From A to B
            (2,C,A,B){
                (1,C,B,A){
                    Move 1st from C to A
                }
                Move 2nd from C to B
                (1,A,C,B){
                    Move 1st from A to B
                }
            }
        }

        Move 4th from A to C

        (3,B,A,C){
            (2,B,C,A){
                (1,B,A,C){
                    Move 1st from B to C
                }
                Move 2nd from B to A
                (1,C,B,A){
                    Move 1st from C to A
                }
            }
            Move 3rd from B to C
            (2,A,B,C){
                (1,A,C,B){
                    Move 1st from A to B
                }
                Move 2nd from A to C
                (1,B,A,C){
                    Move 1st from B to C
                }
            }
        }

    }






*/

#include <bits/stdc++.h>
using namespace std;

void move(int N, char from, char help, char dest, long long &res)
{

    if (N == 0)
        return;
    // move N-1 from source to aux via des
    move(N - 1, from, dest, help, res);
    // source -> target;
    cout << "move disk " << N << " from rod " << from << " to rod " << dest << endl;
    res++;
    // move the N-1 from aux to des via source
    move(N - 1, help, from, dest, res);
}

long long toh(int N, char from, char help, char dest)
{
    long long res = 0;
    move(N, from, help, dest, res);
    return res;
}

int main()
{
    int n;
    cin >> n;
    char from, dest, help;
    cin >> from >> help >> dest;
    cout << toh(n, from, help, dest);
    return 0;
}