// greedy

// optimal strategy is to delete the useless point
// useless point is like "3" between 1 3 4
// for a acending/decending sequence, the mid points are useless
// we only need the endpoints

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        vector<int> p(n), ans;
        for(int i=0; i<n; i++) cin>>p[i];
        int i=0;
        ans.push_back(p[0]);
        while(i < n-1){
            if(i<n-1 && p[i] <= p[i+1]){
                while(i<n-1 && p[i] <= p[i+1]) i++;
                ans.push_back(p[i]);
            }
            else if(i<n-1 && p[i] > p[i+1]){
                while(i<n-1 && p[i] > p[i+1]) i++;
                ans.push_back(p[i]);
            }
        }
        cout<<ans.size()<<endl;
        for(auto x: ans) cout<<x<<" ";
        cout<<endl;
    }

    
    return 0;
}
