// graph + traversal + directed graph + in degree
// if we can't determine the start point, we need to dfs from the end (reverse)

#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int H=1, M=0;
int n,a;
vector<int> type, ans;
unordered_set<int> already;     // make dfs O(n)
unordered_map<int, int> in_deg;
unordered_map<int,vector<int>> g;

void dfs(int x, vector<int> &path){
    if(already.find(x) != already.end() || in_deg[x]>1 || g[x].size() == 0) {
        if(path.size() > ans.size()) ans = path;
        return;
    }
    already.insert(x);
    path.push_back(x);
    for(auto i : g[x]) {
        dfs(i, path);
    }
}
int main(){
    cin>>n;
    type.resize(n+1);
    for(int i=1; i<=n; i++) cin>>type[i];
    for(int i=1; i<=n; i++){
        cin>>a;
        g[i].push_back(a);
        in_deg[a]++;        // used to determine the number of ski tracks (<= 1)
    }
    for(int i=1; i<=n; i++){
        vector<int> cur;
        if(type[i] == H){   // dsf form hotel
            dfs(i, cur);
        }
    }
    int m = ans.size();
    cout<<m<<endl;
    for(int i=m-1; i>0; i--){
        cout<<ans[i]<<" ";
    }
    cout<<ans[0]<<endl;
}