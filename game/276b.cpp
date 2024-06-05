// game

// ps: before the turn, player can reorder the string
// so now we only care about the number of each characters, specially the number of characters which is odd
// (delete operation can make odd number to even, even to odd)

// palindrome1: aabaa   (x even + 1 odd)
// palindrome2: aabb    (x even + 0 odd)

// if the orginal string is like aabb or aaaac -- First win
// 1. all characters are even
// 2. the number of odd character is odd -- First can delete the extra odd character to get palindrome string

// For example: (when the number of odd character is even, Second win)
// aabaacaa
// First: aabaaaa
// Second: reorder, aaabaaa Win


#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    cin>>s;
    unordered_map<int,int> cnt;
    for(auto c: s) cnt[c]++;
    int odd=0;
    for(auto p: cnt) if(p.second%2 == 1) odd++;
    if(odd == 0 || odd%2 == 1) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}
