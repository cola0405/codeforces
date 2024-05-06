<<<<<<< HEAD
// greedy + prefix + analyse + classic
#include<iostream>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;

int t,n;
vector<ll> nums;
=======
// greedy + must + math

// must: you must fill the gap between the left_max and the a[i]
// you can fill the gap using 1+2+4+8+...
// ps: it's not (1+n)*n/2, because it's not a arithmetic sequence !!! -- 1+2+4+8
// it's a geometric sequence !!!
// with the analyse on it, we can find that s = 2^(x-1) - 1 + 2^(x-1) = 2^x - 1
// the inequality is 2^x - 1 >= max_diff
// so the x = ceil(log2(max_diff+1))

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int t,n;
vector<int> a;
>>>>>>> d0eac670cc75a5610ce79ffb87b9367b2ebeca20
int main(){
    cin>>t;
    while(t--){
        cin>>n;
<<<<<<< HEAD
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
=======
        a.resize(n);
        for(int i=0; i<n; i++) cin>>a[i];
        int max_diff = 0;
        int mx = a[0];
        for(int i=1; i<n; i++){
            max_diff = max(max_diff, mx-a[i]);
            mx = max(mx, a[i]);
        }
        if(max_diff <= 0) cout<<0<<endl;
        else cout<<ceil(log2(max_diff+1))<<endl;  
    }
    return 0;
}
>>>>>>> d0eac670cc75a5610ce79ffb87b9367b2ebeca20
