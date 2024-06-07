// prefix

// maybe you can find the pattern that, the "Yes" testcase, the sum of all numbers is 0
// because the pointer need to go right and back to the first element (+1 or -1)
// so the sum of ai must be 0 (which is not difficult to figure out)
// second, we need to make sure there do not have the 0 prefix sum in the middle
// because only back to the first element can make pre=0
// so if there do appear another pre=0, it's impossible

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

bool solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    while(a.size() > 0 && a.back() == 0) a.pop_back();      // deleteing the trailing 0
    if(a.size() == 0) return true;
    ll pre = 0;
    int cnt = 0;
    for(int i=0; i<a.size(); i++){
        pre += a[i];
        if(pre < 0) return false;
        if(pre == 0) cnt++;
    }
    return pre == 0 && cnt <= 1;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        if(solve()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;  
    }
    return 0;
}
