// greedy + math
#include<iostream>
#define ll long long
using namespace std;

ll t,n,x;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        ll sum = 0;
        for(int i=0; i<n; i++){
            cin>>x;
            sum += x;
        }
        ll remain = sum % n;
        cout<<remain * (n-remain)<<endl;
    }
}