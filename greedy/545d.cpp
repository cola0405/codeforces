// classic greedy
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> t(n);
    for(int i=0;i<n;i++) cin>>t[i];
    sort(t.begin(), t.end());
    long long pre = 0, ans = 0;
    for(auto x: t){
        if(pre <= x){   // if the cumstommer will be dispointed, just leave it alone
            ans++;      // wait time is not more than the serve time -- dispointed
            pre += x;   
        }
    }
    cout<<ans<<endl;
    return 0;
}
