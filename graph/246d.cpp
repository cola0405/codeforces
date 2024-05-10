// not all graph problems need dfs

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int n,m;
vector<int> c;
unordered_map<int, unordered_set<int>> g;
int main(){
    cin>>n>>m;
    c.resize(n+1);
    for(int i=1; i<=n; i++) cin>>c[i];
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        if(c[x] != c[y]){           // only the different color could be neighbors
            g[c[x]].insert(c[y]);
            g[c[y]].insert(c[x]);
        }
    }
    int ans = -1;
    for(auto &[color, colors]: g){
        if(ans == -1 || colors.size() > g[ans].size())  ans = color;
        else if(colors.size() == g[ans].size()) ans = min(ans, color);
    }
    if(ans == -1) {     // g is empty, all Q(k) = 0, so we pick up the minimum color here
        cout<<*min_element(c.begin()+1, c.end())<<endl;
        return 0;
    }
    cout<<ans<<endl;
}