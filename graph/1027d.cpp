// graph traversal + cycle

// "ai" is saying that when mouse at room i, it will go to ai room
// and we don't know where the mouse start, so we can't just easily find the minimal ci

// because there do have n vertices and n edges, so there must have cycle
// and every room have out-degree, so we just need to focus the destination -- cycle
// the graph will be like some nodes point to a cycle
// so our goal is to find the minimal cost of each cycle

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int n;
int main()
{
    cin>>n;
    vector<int> c(n+1), nxt(n+1), visit(n+1,0);
    for(int i=1; i<=n; i++) cin>>c[i];
    for(int i=1; i<=n; i++) cin>>nxt[i];
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(visit[i]) continue;
        int cur = i;
        while(!visit[cur]){     // dfs
            visit[cur] = i;     // special mark
            cur = nxt[cur];
        }
        if(visit[cur] != i) continue;       // make sure cur is visted by current dfs

        // travel along cycle to find min cost
        int cur1 = cur;
        int min_cost = c[cur1];
        while(nxt[cur1] != cur){
            cur1 = nxt[cur1];
            min_cost = min(min_cost, c[cur1]);
        }
        ans += min_cost;
    }
    cout<<ans<<endl;
    return 0;
}
