// analysis

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n,f;
    cin>>n>>f;
    vector<int> p(n), c(n), extra(n);
    for(int i=0; i<n; i++) cin>>p[i]>>c[i];
    ll ans = 0;
    for(int i=0; i<n; i++){
        extra[i] = min(2*p[i], c[i]) - min(p[i], c[i]);     // extra money
        ans += min(p[i], c[i]);
    }
    sort(extra.begin(), extra.end(), greater<int>());
    for(int i=0; i<f; i++) ans += extra[i];                 // select the f-first elements
    cout<<ans<<endl;
    return 0;
}
