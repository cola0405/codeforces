// the ans is at least 1

// why the largest interval always start from 1?
// you can assume the left of interval is not 1 and [l,r] is greater than 1
// but what you need to know is that if x % [l,r] == 0
// then the x can must be divided by 1,2,3,...
// so the largest interval should start from 1

#include<iostream>
#define ll long long
using namespace std;

ll t,x;
int main(){
    cin>>t;
    while(t--){
        cin>>x;
        ll num = 1;
        while(num <= x){
            if(x%num != 0) break;
            num++;
        }
        cout<<num-1<<endl;
    }
    return 0;
}