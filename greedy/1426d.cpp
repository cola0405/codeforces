// prefix + interval + greedy

// if pre[i] == pre[j], then there do exist a interval whose sum is 0
// for every interval we "must" insert a number into it
// notice that after the insertion, all the following pre[i] will increase by the inserted number
// so there may exist a situation that the following pre[j] will increased to the previous pre[i]
// to avoid this situation, we need to holding the greedy strategy
// insert a super big number to avoid the situation to minimize the number of operations

// next, we need to consider the minimal number of the operations
// we can't just simply do ans += cnt[pre]-1;
// because the insertion can help us to reduce the number of operations
// example: 0 -1 0 -1 0
// insert add 100 to the second 0, then we can get 0 -1 100 99 100
// when we dealing with the pre[0] and pre[2], the pre[1] and pre[3] is also be solved
// so we can calculate the answer as this program in a greedy way


#include<iostream>
#include<unordered_set>
#define ll long long
using namespace std;

int n, ans=0;
ll a,pre=0;
unordered_set<ll> s = {0};

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        pre += a;
        if(s.find(pre) != s.end()){     
            ans++;
            pre = a;
            s = {0};
        }
        s.insert(pre);
    }
    cout<<ans<<endl;
}