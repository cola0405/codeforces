#include<bits/stdc++.h>
using namespace std;

int n,a,p;
int main(){
    cin>>n;
    int ans = 0;
    int low_price = 1e9;
    while(n--){
        cin>>a>>p;
        if(p < low_price) low_price = p;
        ans += a*low_price;
    }
    cout<<ans<<endl;
    return 0;
}