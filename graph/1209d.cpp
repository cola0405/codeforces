// connected component + dsu

// the two flavor a and b can be treated as the edge in a graph, and there do have n vertices and k edges
// the conflict happen in a connected component
// for a cc with x vertices, it's always possible to find an order(like bfs order) to satisfy x-1 animals
// so optimally, we can satisfy n-c animal, c is the number of cc
// the sad animal is k-(n-c)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> par;
int root(int x){
    if(par[x] == x) return x;
    par[x] = root(par[x]);
    return par[x];
}
int main()
{
    int n,k,a,b;
    cin>>n>>k;
    par.resize(n+1);
    for(int i=1; i<=n; i++) par[i] = i;
    for(int i=0; i<k; i++){
        cin>>a>>b;
        if(root(a) != root(b)){
            par[root(a)] = par[root(b)];
        }
    }
    unordered_set<int> s;
    for(int i=1; i<=n; i++) s.insert(root(i));
    cout<< k - (n-s.size()) <<endl;
    return 0;
}
