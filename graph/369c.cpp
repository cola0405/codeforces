// dfs return value + subtree + testcase
#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int n,x,y,t;
vector<int> ans;
unordered_map<int, vector<pair<int,int>>> g;    // {node: {{next, type}, {next, type}, ...}}

int dfs(int x, int parent){
    if(x!=1 && g[x].size()==1) return 0;        // leaf vertex
    int res = 0;
    for(auto &[next, type]: g[x]){
        if(next == parent) continue;
        if(type == 1) res += dfs(next, x);
        else {
            int cnt = dfs(next, x);     // the number of bad road of each subtree
            if(cnt == 0) ans.push_back(next);
            res += max(cnt, 1);         // "1" means the previous bad road (x,next)
        }
    }
    return res; 
}

int main(){
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>x>>y>>t;
        g[x].push_back({y,t});
        g[y].push_back({x,t});
    }
    dfs(1, -1);
    cout<<ans.size()<<endl;
    if(ans.size() == 0) return 0;
    for(int i=0; i<ans.size()-1; i++) cout<<ans[i]<<" ";
    cout<<ans.back()<<endl;
    return 0;
}