#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    unordered_map<int,int> cnt;
    for(auto c: s) cnt[c]++;
    vector<int> a;
    for(auto p: cnt) a.push_back(p.second);
    sort(a.begin(), a.end(), greater<int>());
    long long ans = 0, mn;
    for(int i=0; i<a.size(); i++){
        if(k<=0) break;
        mn = min(k, a[i]);
        ans += mn*mn;       // the price is equal to the number of selling
        k -= a[i];
    }
    cout<<ans<<endl;
    return 0;
}
