// greedy + difference

// it's easy to find that the two decrease operation will only change a element in diff array
// and our target is to all elements in diff become 0, so we need to add all abs(diff)
// but pay attention, all diff become 0 doesn't means that we make "a" to 0
// look at the example:
// array: 10  4  7
// diff:  -6  3
// and the procedure will be like:
// 4 4 7
// 7 7 7
// which means we need to modify all elements to 0 in the end
// and we can get the final number from a[0] through the iteration -- the only operation will affect a[0] is "decrease operation from 0 to i"


#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int t,n,a,pre,diff;

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        ll ans = 0, final = a[0];
        for(int i=1; i<n; i++){             
            diff = a[i-1] - a[i];
            ans += abs(diff);               
            if(diff > 0) final -= diff;     // diff > 0 means falling down, and we must do the decrease operation, and the "final" should be updated
        }
        cout<<ans + abs(final)<<endl;       // final is the target number for every ai, then we need to modify it to 0 by decrease or increase
    }
    
    return 0;
}
