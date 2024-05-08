// constructive 

// x or y must exist in the first pair
// so we can assume this two situation
// now, we have already figure out a number -- we call it "x"
// then we just need to find out another number exist or not
// solution: check whether there exist a number whose count is equal to the number "x" can't solved

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int n,m,a,b;
vector<pair<int,int>> p;
unordered_map<int,int> cnt; 

bool fit(int x){
    int y = 0;
    cnt = {};
    for(auto &[a,b] : p){
        if(a == x || b == x) continue;
        cnt[a]++;
        cnt[b]++;
        y++;
    }
    if(y == 0) return true;
    for(auto item: cnt) if(item.second == y) return true;
    return false;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        cin>>a>>b;
        p.push_back({a,b});
    }
    if(fit(p[0].first) || fit(p[0].second)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}