// greedy(must) + io optimization
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int t,n;
vector<ll> a(310000), b(310000);
int main(){
    ios_base::sync_with_stdio(0);   // close the synchronization between input and output streams
    cin.tie(0);                     // when the input stream work, the system will flush the buffer of output stream
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i]>>b[i];
        ll ans = 0, min_start = LLONG_MAX;
        for(int i=0; i<n; i++){
            int p = (i-1+n)%n;
            ans += max(0ll, a[i]-b[p]); 
            min_start = min({min_start, a[i], b[p]});
        }
        ans += min_start;
        cout<<ans<<"\n";
    }
    return 0;
}