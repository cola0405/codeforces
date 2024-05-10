// in degree + dfs for section
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int n,x,y,max_deg=0;
unordered_map<int, vector<int>> g;
unordered_map<int, int> in_deg;
vector<int> c;      // color

void dfs(int x, int parent){
    vector<int> available;
    for(int color=1; color<=max_deg+1; color++){        // time complexity is still O(n)
        if(color != c[x] && color != c[parent]){        // select the color different from the cur and parent for sub-nodes
            available.push_back(color);
            if(available.size() >= g[x].size()) break;
        }
    }
    for(auto next: g[x]){
        if(next == parent) continue;
        c[next] = available.back();
        available.pop_back();
        dfs(next, x);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        in_deg[x]++;
        in_deg[y]++;
    }
    for(auto &[node, deg]: in_deg){
        max_deg = max(max_deg, deg);
    }
    cout<<max_deg+1<<endl;     
    c.resize(n+1);
    c[1] = 1;
    dfs(1, 1);
    for(int i=1; i<=n; i++) cout<<c[i]<<" ";
    cout<<endl;
    return 0;
}