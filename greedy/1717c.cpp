// analyse

// impossible1: a[i] > b[i]
// impossible2: a[i] != b[i] && b[i] - b[i+1] > 1, which is impossible

#include <iostream>
#include <vector>
using namespace std;

bool solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++){
        if(a[i] == b[i]) continue;
        if(a[i] > b[i] || b[i] - b[(i+1)%n] > 1) return false;
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
