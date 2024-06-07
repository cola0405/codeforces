// game + analyse

// don't always trying to simulation the whole game
// the important thing is to figure out the pattern
// actually Alice don't care the elements that appear more than once
// Alice will pick up the the smallest element, which only appear once
// for Bob, the mission is to find the second smallest element, which only appear once
// and we also need to detect the missing element

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    unordered_map<int,int> cnt;
    for(int i=0; i<n; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int mx = *max_element(a.begin(),a.end());
    int flag = 0;
    for(int i=0; i<=mx; i++){
        if(cnt[i] == 0){        // missing element
            cout<<i<<endl;
            return;
        }
        if(cnt[i] == 1){
            if(flag){
                cout<<i<<endl;      // second smallest element which only appear once
                return;
            }
            flag = 1;
        }
    }
    cout<<mx+1<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
