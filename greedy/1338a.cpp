// greedy + prefix + analyse + classic
#include<iostream>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;

int t,n;
vector<ll> nums;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        nums.resize(n);
        for(int i=0; i<n; i++) cin>>nums[i];

        int x = 0;
        int pre = 0;
        for(int i=1; i<n; i++){
            ll gap = nums[i-1] - nums[i];
            int tmp = pre;
            while(nums[i-1] - (nums[i]+pre) > 0){
                x++;
                nums[i] += pow(2, x-1);
                tmp += pow(2, x-1);
            }
            pre = tmp;
        }
        cout<<x<<endl;
    }
    return 0;
}