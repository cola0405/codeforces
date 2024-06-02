// dfs + greedy

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> c;
unordered_map<int,vector<int>> g;
unordered_map<int,int> cnt;     // count of colors
unordered_set<int> already;
int dfs(int node){
    if(already.find(node) != already.end()) return 0;
    int res = 1;
    cnt[c[node]]++;
    already.insert(node);
    for(auto next: g[node]){
        res += dfs(next);
    }
    return res;
}

int main()
{
    int n,m,k,a,b,ans=0;
    cin>>n>>m>>k;
    c.resize(n+1);
    for(int i=1; i<=n; i++) cin>>c[i];
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(auto &[node, next]: g){
        if(already.find(node) != already.end()) continue;
        cnt.clear();
        int sz = dfs(node);
        int most_common = c[node];      // turn all into most common color is optimal
        for(auto &[color, count]: cnt){
            if(count > cnt[most_common]) most_common = color;
        }
        ans += sz - cnt[most_common];
    }
    cout<<ans<<endl;
    return 0;
}
