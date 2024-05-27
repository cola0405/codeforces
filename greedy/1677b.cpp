// math + 2d

// we can divide this problem to count the vaild coulmns and rows
// column: the new student will never reduce the valid columns, so we only need to detect the new column
// you can consider '101010' in a line, even all 0 comes in, but the existing 1s will not overlap to reduce the columns
// even though we know this, but it's still not easy to detect the new column for the moveing matrix

// here we will build an array "col", whose length is equal to m, to record the change of the valid column
// to fit the moving matrix and changing status, we need an array "col"
// the moving matrix will act like below:
// ####  ->  ####  ->  ####  ->  ####  ->  ####  ->  ####  ......
// #         ##        ###       ####      ####      ####
//                                         #         ##

// observation: the head of the matrix is change like modulo !!!
// every m students comes in will let all rows move down 1 unit with the origin status !!
// example:
// 1010  ->  0000
//           1010
// so even though we can't iterate on i, i+1, i+2, ...
// but we can iterate for every m step with modulo
// the status can be iterated on i, i+m, i+2m, ...
// 00100  -> 00100  ->  00100
//           11111      11111
//                      110
// the previous rows will stay at original status, so we can iterate on it

// ok, let's go back to the column counting
// we can use col[i%m] to record the status of the columns separately and properly
// and col[1] represent the status of the whole column from top to bottom:
// 0[0]100
// 1[1]111
// 1[1]0
// so when there do have "1" appear in this column, column_cnt++
// (pay attention, col[] only used for record the status, not the number of column)

// then let's talk about row
// we will use the same method to record the changing of rows, because of the moving matrix
// i, i+m, i+2m, ... is the only way of iteration, because the previous rows will keep the original status
// so we need the row[i%m] (pay attention, it's not %n)
// so how to detect the new valid row?
// for row[i], row[i+1], row[i+2],... row[i+m-1], base on the iteration
// we only need to detect whether "1" exist in the first row or not

// row[1]
// 01  ->  00001  ->  00000
//         01         00001
//                    01

// the solution is making a judgment: if(i-last < m)
// the distance between s[i] (matrix[0][0]) and last "1" is <= m
// which means there must have "1" in the current first row, so row[i%m]++

#include <iostream>
#include <vector>
using namespace std;

int t,m,n;
string s;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);   
    cin>>t;
    while(t--){
        cin>>n>>m>>s;
        vector<int> col(m), row(m);
        int c=0, last=-1e9;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                if(col[i%m] == 0) c++;      // new valid column
                col[i%m] = 1;
                last = i;
            }
            if(i-last < m) row[i%m]++;      // check the first row
            cout<<c + row[i%m]<<" ";        // count the columns and rows
        }
        cout<<"\n";
    }
    
    return 0;
}
