// greedy + iteration flags
// for greedy, there only got 4 ways to reach the minimal opeations
// 1.only shift;                 example: 2 3 4 5 1 
// 2.reverse + shift + reverse;  example: 8 1 2 3 4 5 6 7
// 3.shift + reverse;            example: 3 2 1 5 4
// 4.reverse + shift;            example: 2 1 6 5 4 3


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n;
vector<int> a, up, down;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        a.resize(2*n);
        for(int i=0; i<n; i++){
            cin>>a[i];
            a[n+i] = a[i];
        }
        up={0}, down={0};
        for(int i=1; i<2*n; i++){   // iteration flags
            if(a[i]>=a[i-1]) up.push_back(up.back()+1);     // increasing order
            else up.push_back(0);
            if(a[i]<=a[i-1]) down.push_back(down.back()+1); // decreasing order
            else down.push_back(0);
        }
        if(up[n-1] == n-1) {        // already sorted
            cout<<0<<endl;
            continue;
        }
        int ans = INT_MAX;
        for(int i=n-1; i<2*n; i++){
            if(up[i] == n-1) ans = min({ans, 2*n-i-1, i-n+3});  // only shift; reverse + shift + reverse
            if(down[i] == n-1) ans = min({ans, 2*n-i, i-n+2});  // shift + reverse; reverse + shift
        }
        if(ans == INT_MAX) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}