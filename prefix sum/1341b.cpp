// prefix to sove window problem
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int t,n,k,h;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> a(n);
        vector<ll> pre(n+1);
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=1; i<n-1; i++){
            if(a[i] > a[i-1] && a[i] > a[i+1]) pre[i+1] = pre[i] + 1;
            else pre[i+1] = pre[i];
        }
        ll ans = 0, inx = 0;
        for(int i=0; i<=n-k; i++){              // build the prefix normally, just need to shrink the interval (left and right)
            int cnt = pre[i+k-1]-pre[i+1];      // because the endpoint can't be the peek
            if(cnt > ans){
                ans = cnt;
                inx = i;
            }
        }
        cout<<ans+1<<" "<<inx+1<<endl;
    }
    
    return 0;
}
