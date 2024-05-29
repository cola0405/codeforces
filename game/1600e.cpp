// game

// let's consider two things
// 1.longest increasing prefix -- q1
// 2.reverse of longest decreasing suffix -- q2

// Example: 5 8 2 1 10 9
// q1 = {5,8}  (contiguous subsequence)
// longest decreasing suffix = {10,9}  (require end at rightmost endpoint)
// q2 = {9,10}   (to fit the order of the numbers in the game)

// (1) if the length of q1 and q2 are both odd number, the Alice win
// Explain: because Alice will play optimally, so she will use the trick -- pick up the endpoint of a odd length sequence
// because it will let Bob have no number to pick up in the end

// (2) both even number, the bob win 
// Explain: Alice meet with the situation that she can't win

// (3) when the length is odd + even, Alice will win
// Explain: Alice can choose the odd first, then Bob will meet with two even sequence, lose

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    // increasing prefix
    int i=0;
    while(i<n-1 && a[i]<a[i+1]) i++;
    int inc_pre = i+1;
    // decreasing suffix
    int j=n-1;
    while(j>=0 && a[j]<a[j-1]) j--;
    int dec_suf = n-j;
    if(inc_pre&1 || dec_suf&1) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
    return 0;
}
