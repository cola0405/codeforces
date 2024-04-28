#include<bits/stdc++.h>
using namespace std;

int t,n;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        if(n%2 == 1) cout<<7;
        else cout<<1;

        int m = n/2-1;
        while(m > 0){
            cout<<1;
            m--;
        }
        cout<<endl;
    }
    return 0;
}