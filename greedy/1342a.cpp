// greedy
#include<iostream>
#define ll long long
using namespace std;

ll t,x,y,a,b;
int main(){
    cin>>t;
    while(t--){
        cin>>x>>y>>a>>b;
        ll res1 = (abs(x)+abs(y)) * a;
        if(x*y<0) cout<< res1 <<endl;
        else {
            x = abs(x);
            y = abs(y);
            ll res2 = min(x, y)*b + (x+y - 2*min(x, y))*a;
            cout<<min(res1, res2)<<endl;
        }
    }
}