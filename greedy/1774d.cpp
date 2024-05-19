// greedy + analysis
#include <iostream>
#include <vector>
using namespace std;

int t,n,m,x;
vector<vector<int>> a;
vector<int> cnt1;

void solve(){
    cin>>n>>m;
    a.resize(n+1);
    cnt1.resize(n+1);
    int total = 0;
    for(int i=1; i<=n; i++){
        a[i] = {0};
        cnt1[i] = 0;
        for(int j=1; j<=m; j++){
            cin>>x;
            a[i].push_back(x);
            if(x == 1){
                cnt1[i]++;
                total++;
            }
        }
    }
    if(total%n != 0){
        cout<<-1<<endl;
        return;
    }
    int s = total/n;            // if is't possible to finish the task, the number of 1s is fixed
    vector<string> ans;
    for(int c=1; c<=m; c++){    // loop through each columns
        vector<int> extra,lack;
        for(int r=1; r<=n; r++){    // loop through each rows
            if(a[r][c] == 1 && cnt1[r] > s) extra.push_back(r);         // we must dealing with extra
            else if(a[r][c] == 0 && cnt1[r] < s) lack.push_back(r);     // we must dealing with lack
        }
        for(int i=0; i<extra.size() && i<lack.size(); i++){     // once we find the extra 1s and lack 1s, we can swap them 
            int r1 = extra[i], r2 = lack[i];                    // we can pick up the pos randomly, just make sure we swap in the same column
            cnt1[r1]--;
            cnt1[r2]++;
            ans.push_back(to_string(r1) + " " + to_string(r2) + " " + to_string(c));
        }
    }
    for(int r=1; r<=n; r++){
        if(cnt1[r] != s) {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans.size()<<endl;     // not sure it's successful or not, so store the operation in ans first
    for(auto &s: ans) cout<<s<<endl;
}

int main()
{
    cin>>t;
    while(t--) solve();
    return 0;
}
