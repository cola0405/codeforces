// prefix sum
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> a, pre;

int main(){
    cin>>n;
    a.resize(n);
    pre.resize(n+1);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i-1];
    int ans = 0;
    for(int i=1; i<n; i++){
        if(pre[i] == pre.back()-pre[i]) ans++;
    }
    cout<<ans<<endl;
}