// graph + directed graph + cycle detection

// the minimal op = the number of rooks - self_loop + cycle_cnt
// self_loop like (2,2) don't need to move 
// a cycle is a group of points that limit with each other -- it need a extra move

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int t,n,m,x,y;
unordered_map<int,int> g;       // directed graph, {a:b} (a->b)
vector<int> visted;

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        visted.resize(n+1);
        for(int i=1; i<=n; i++) visted[i] = 0;
        g.clear();
        int self_loop = 0, cycle_cnt = 0;
        for(int i=0; i<m; i++){
            cin>>x>>y;
            if(x == y){
                self_loop++;
                continue;
            }
            g[x] = y;
        }
        for(auto &[src,dst]: g){
            if(visted[src]) continue;
            int cur = src;
            while(visted[cur] == 0){
                visted[cur] = 1;
                cur = g[cur];
            }
            if(cur == src) cycle_cnt++;
        }
        cout<<m - self_loop + cycle_cnt<<endl;
    }
}