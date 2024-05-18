#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int t,n,m,x;
vector<int> a,cnt;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        a.resize(n);
        cnt.resize(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            cnt[i] = i;
        }
        int me = 0;
        for(int i=n-1; i>=0; i--){
            if(m >= a[i]){
                m -= a[i];
                me++;
            }else{
                cnt[i]++;
            }
        }
        sort(cnt.begin(), cnt.end());
        int ans = 1, i = n-1;
        while(i>=0 && cnt[i] > me){
            i--;
            ans++;
        }
        cout<<ans<<endl;
    }
}