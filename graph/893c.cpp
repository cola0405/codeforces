// graph
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
unordered_map<int, vector<int>> g;
unordered_set<int> already;
vector<int> c;
int dfs(int x, int min_cost){
    if(already.find(x) != already.end()) return 2e9;
    min_cost = min(min_cost, c[x]);
    already.insert(x);
    for(auto next : g[x]){
        min_cost = min(min_cost, dfs(next, min_cost));
    }
    return min_cost;
}
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    c.resize(n+1);
    for(int i=1; i<=n; i++) cin>>c[i];
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        if(already.find(i) == already.end()) {
            ans += dfs(i, c[i]);        // dfs to find the min_cost of traversal
        }
    }
    cout<<ans<<endl;
    return 0;
}
