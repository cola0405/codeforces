// greedy + math
// to minimize the operation, we need to maximize the number of elements that are already in the correct order
// focus on 1, because this is the element that we have to sort
// assume the length of the correct subsequence is x
// the number of operations needed is (n-x + (k-1)) / k
// +k-1 aims to get the ceil of the division
#include<bits/stdc++.h>
using namespace std;

int t,n,k,x;
vector<int> nums;

int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        nums.resize(n);
        int start = 1;
        for(int i=0; i<n; i++){
            cin>>x;
            if(x == start) start++;
        }
        cout<<(n-(start+1) + k-1)/k<<endl;
    }
    return 0;
}