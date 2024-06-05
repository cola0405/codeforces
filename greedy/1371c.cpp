// analyse

// 1. make sure the cookies is enough
// 2. the rule is actually limit the guest with type 2

// let's consider two situation
// 1. v > c, then the guest2 will choose the c
// we have to make sure c >= m
// 2. v < c, then the guest2 will choose the v
// we have to make sure v >= m

// summary: m <= min(v, c)

// for guest1
// 1. v > c, then the guest1 will choose the v
// we have to make sure v >= n
// 2. v < c, then the guest1 will choose the c
// we have to make sure c >= n

// summary: n <= max(v,c), which is already comfirm by m <= min(v,c)
// but pay attention: n <= max(v,c) can't make sure m <= min(v,c)
// so we need check m <= min(v,c), not n <= max(v,c)

// example:
// 0 100 0 1


#include <iostream>
using namespace std;

int main()
{
    long long t,a,b,n,m;
    cin>>t;
    while(t--){
        cin>>a>>b>>n>>m;
        if(a+b >= n+m && m <= min(a,b)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
