// dfs
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int ROOT=1;
int n,m,a,b,ans=0;
vector<int> cats;
unordered_map<int, vector<int>> g;
unordered_set<int> already;

void dfs(int node, int cat){
    if(already.find(node) != already.end()) return;
    if(cats[node]) cat++;
    else cat = 0;
    if(cat > m) return;
    if(node != ROOT && g[node].size() == 1) {   // leaf vertex
        ans++;
        return;
    }
    already.insert(node);
    for(auto nxt: g[node]) dfs(nxt, cat);
}

int main(){
    cin>>n>>m;
    cats.resize(n+1);
    for(int i=1; i<=n; i++) cin>>cats[i];
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    cout<<ans<<endl;
}