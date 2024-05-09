// dsu + fully connected graph

// ans = fully connected edges - current edges + new edges
// the problem: add the edges in every disjoint set
// solution:
// 1. build the disjoint set (there may exist some disjoint sets which are not a nation)
// 2. calculate the size of each disjoint set
// 3. add new edges after merge


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int n,m,k,a,b,t;
vector<int> root,home;
unordered_map<int,int> cnt;

int pra(int x){
    if(x != root[x]) root[x] = pra(root[x]);
    return root[x];
}
int f(int x){
    return x*(x-1)/2;
}

int main(){
    cin>>n>>m>>k;
    root.resize(n+1);
    for(int i=1; i<=n; i++) root[i] = i;    // disjoint set initialization
    for(int i=0; i<k; i++){
        cin>>t;
        home.push_back(t);
    }
    for(int i=0; i<m; i++){
        cin>>a>>b;
        // roughly merge here, because we only need to know the size of the block
        root[pra(a)] = pra(b);      
    }
    int ans = 0;
    int max_set=0, single=n;
    for(int i=1; i<=n; i++) cnt[pra(i)]++;      // calculate the size of each block
    for(auto x : home) {    
        x = pra(x);     // the solution to the roughly merge
        ans += f(cnt[x]);   // full connected
        max_set = max(max_set, cnt[x]);
        single -= cnt[x];   // distract the block of nation
    }
    ans -= f(max_set);          // distract the original full connected edges
    ans += f(max_set+single);   // add it back after merge
    ans -= m;                   // avoid repeat
    cout<<ans<<endl;
}