// greedy + float

// our approach is to increase the denominator
// we can just add to p0, which is equlevant to add to multi denominator

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
    int t,n;
    double k;        // for accurate calculation
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> p(n);
        for(int i=0;i<n;i++) cin>>p[i];
        ll pre = p[0], ans = 0;
        for(int i=1; i<n; i++){
            ans = max(ans, ll(ceil((p[i]*100ll - pre*k) / k)));
            pre += p[i];
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
