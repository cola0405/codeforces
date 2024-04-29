#include<iostream>
#include<vector>
using namespace std;

int t,k,n,m;
vector<int> a,b;

void solve(){
    int i=0, j=0;
    vector<int> ans;
    cin>>k>>n>>m;
    a.resize(n);
    b.resize(m);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    while(i<n || j<m){
        if(j==m || (i<n && a[i]<=k)){
            if(a[i]==0) k++;
            else if(a[i] > k){
                cout<<-1<<endl;
                return;
            }
            ans.push_back(a[i]);
            i++;
        }else{
            if(b[j]==0) k++;
            else if(b[j] > k){
                cout<<-1<<endl;
                return;
            }
            ans.push_back(b[j]);
            j++;
        }
    }
    for(int i=0; i<ans.size()-1; i++) cout<<ans[i]<<" ";
    cout<<ans.back()<<endl;
}

int main(){
    cin>>t;
    while(t--) solve();
    return 0;
}