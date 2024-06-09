// greedy + precision problem of float

// take the heavy as you can
// consider this situation:
// w = 10
// v = 3,3,8
// it's optimal to take 8 first

// there do have the precision problem of float when we do "if(cur < (float)w/2.)"
// but we can use multiplication to avoid it

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        long long n,w;
        cin>>n>>w;
        vector<pair<int,int>> a(n);
        for(int i=0; i<n; i++) {
            cin>>a[i].first;
            a[i].second = i+1;
        }
        sort(a.begin(), a.end(), greater<pair<int,int>>());     // descending order
        long long cur = 0;
        vector<int> ans;
        ans.reserve(n);
        for(auto &[x, inx]: a){
            if(cur + x <= w){
                ans.push_back(inx);
                cur += x;
            }
        }
        // C++ is a strongly typed language, when comparing, the long long is cast to float/double
        // if(cur < (float)w/2.) cout<<-1<<endl;    error  (can't hold enough digtis for 10^18 -- only 23 bits)
        // if(cur < (double)w/2) cout<<-1<<endl;    accept (double hold more digits)
        if(cur * 2 < w) cout<<-1<<endl;             // avoid the float calculation
        else{
            cout<<ans.size()<<endl;
            for(auto x: ans) cout<<x<<" ";
            cout<<endl;
        }
    }
    return 0;
}
