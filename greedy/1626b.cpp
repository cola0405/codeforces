// analyse

// for the reduction, there only do have two situation:
// 1. the two digits >= 10, you can keep the n digits
// 2. the two digits < 10, you can only keep the n-1 digits

// for case 1, you should start from the right to left to put the reduction as right as possible
// for case 2, you need to pick up the first two digits, to make the left as large as possible
#include<iostream>
#include<string>
using namespace std;

int t,a,b;
string x;

void solve(){
    cin>>x;
    int n = x.size();
    for(int i=n-2; i>=0; i--){       // you should start from the right to left -- example: 4499
        int num = x[i]-'0' + x[i+1]-'0';
        if(a+b >= 10){
            for(int j=0; j<i; j++) cout<<x[j];
            cout<<a+b;
            for(int j=i+2; j<n; j++) cout<<x[j];
            cout<<endl;
            return;
        }
    }
    int left = x[0]-'0' + x[1]-'0';
    cout<<left;
    for(int i=2; i<n; i++) cout<<x[i];
    cout<<endl;
}

int main(){
    cin>>t;
    while(t--) solve();
}