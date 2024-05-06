#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n;
vector<int> a, up, down;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        a.resize(2*n);
        for(int i=0; i<n; i++){
            cin>>a[i];
            a[n+i] = a[i];
        }
        up={0}, down={0};
        for(int i=0; i<2*n-1; i++){
            if(a[i]<=a[i+1]) up.push_back(up.back()+1);
            else up.push_back(0);
            if(a[i]>=a[i+1]) down.push_back(down.back()+1);
            else down.push_back(0);
        }
        
        int ans = INT_MAX;
        for(int i=n; i<=2*n; i++){
            if(up[i] == n-1) ans = min({ans, 2*n-i-1, i-n+3});
            if(down[i] == n-1) ans = min({ans, 2*n-i, i-n+2});
        }
        if(ans == INT_MAX) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}