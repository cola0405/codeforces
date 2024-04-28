// greedy
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int t,n;
vector<ll> a;

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        a.resize(n);
        for(int i=0; i<n; i++) cin>>a[i];
        int i = 0;
        while(i < n && a[i] == 0) i++;      // skip the leading zeros
        ll ans = 0;
        for(;i<n-1;i++){
            ans += a[i];            // for room-i, we at least need a[i] operations
            if(a[i] == 0) ans++;    // when meet with the empty room +1
        }
        cout<<ans<<endl;
    }   
    return 0
}