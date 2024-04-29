// math + analyse
#include<iostream>
#include<vector>
using namespace std;

int n, x;
vector<int> remainder1, remainder2, remainder0;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        if(x%3 == 0) remainder0.push_back(x);
        else if(x%3 == 1) remainder1.push_back(x);
        else if(x%3 == 2) remainder2.push_back(x);
    }
    int cnt0 = remainder0.size();
    int cnt1 = remainder1.size();
    int cnt2 = remainder2.size();
    int ans = cnt0/2 + min(cnt1, cnt2);
    cout<<ans<<endl;
    return 0;
}