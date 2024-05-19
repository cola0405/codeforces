// greedy

// tips: initially the win count is: 0 1 2 3 ...
// (opponent i plays against the opponent j, he wins if and only if i>j)

// let's be greedy first, win as many as possible
// asumming we win x times, the player with index > x will not effect you 
// (because you will never have chance to win more than them)
// the key player is who got the same win count with you -- a[win]
// if you win the player, your rank is n+1-x + 1
// or else your rank is n+1-x

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int t,n,m,x;
vector<int> a,cnt;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        a.resize(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        auto a1 = a;                    // a1 is the copy of a
        int x = 0;                      // the win count
        sort(a1.begin(), a1.end());     // sort a1
        for(int i=0; i<n; i++){
            if(m >= a1[i]) {
                m -= a1[i];
                x++;
            }
        }
        // a1[x-1] is the maximal cost, no worries about didn't pick up which player to win optimally
        // when m + a1[x-1] >= a[x] we choose to win a[x], but the total win count is the same like before
        // the only difference is we may defeat different players -- a1[x-1] or a[x]
        // here, even though the count is the same, but the rank could be different
        // example:
        // 3 2
        // 1 2 3
        // x!=0 && x!=n is to avoid out of boundary
        if(x!=0 && x!=n && m + a1[x-1] >= a[x]) x++;
        cout<<n+1-x<<endl;
    }
}