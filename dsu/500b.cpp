// dsu
// the prolblem is actually want a smallest permutation
// problem didn't limit the time of swap
// so in a disjoint set, we can sort them in increasing order (don't need to consider the actual operation)
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> p, root;
vector<string> mat;
unordered_map<int, vector<int>> g;

int par(int x){
    if(x != root[x]) root[x] = par(root[x]);
    return root[x];
}

int main(){
    cin>>n;
    p.resize(n);
    mat.resize(n);
    root.resize(n+1);
    for(int i=0; i<n; i++) cin>>p[i];
    for(int i=0; i<n; i++) cin>>mat[i];
    for(int i=0; i<n; i++) root[i] = i;     // dsu initialzation
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == '1'){
                if(par(i) != par(j)) root[par(i)] = par(j);
            }
        }
    }
    for(int i=0; i<n; i++) g[par(i)].push_back(i);
    for(auto &[r, inx] : g){        // sort the number in the same disjoint set and insert them back
        vector<int> a;
        for(auto i : inx) a.push_back(p[i]);
        sort(a.begin(), a.end());
        sort(inx.begin(), inx.end());
        for(int i=0; i<inx.size(); i++) p[inx[i]] = a[i];
    }
    for(int i=0; i<n; i++) cout<<p[i]<<" ";
}
