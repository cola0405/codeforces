// graph + game

#include <iostream>
#include <unordered_map>
#include<vector>
#include <unordered_set>
using namespace std;

int n,x,a,b;
unordered_map<int,vector<int>> g;
vector<int> aa;      // record the earliest time of Alice arrival at each node
unordered_set<int> already;
void alice(int x, int time){
    if(already.find(x) != already.end()) return;
    already.insert(x);
    aa[x] = time;
    for(auto next: g[x]){
        alice(next, time+1);
    }
}

int bob(int x, int time){
    if(already.find(x) != already.end()) return max(aa[x],time)*2;
    already.insert(x);
    if(aa[x] <= time) return max(aa[x],time)*2;     // return when Alice can catch Bob
    int ans = max(aa[x],time)*2;                    // or else keep going
    for(auto next: g[x]){
        ans = max(ans, bob(next, time+1));
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>x;
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    aa.resize(n+1);
    alice(1, 0);    // dfs seach the earliest time of Alice arrival at each node
    already.clear();
    cout<<bob(x, 0)<<endl;  // dfs seach the every possible traverl of Bob
    return 0;
}
