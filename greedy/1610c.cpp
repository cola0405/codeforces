// binary search + greedy

// there is nothing you have to do
// so the strategy is binary search the upper bound
// binary search check: invite the people as you can in a greed way

// observation: "His i-th friend has i dollars" is kind of "sorting" -- monotony 

#include <iostream>
#include <vector>
using namespace std;

int t,n,a,b;

bool ok(vector<pair<int,int>> &v, int x){
    int already = 0;            // the number of invitation
    for(int i=v.size()-1; i>=0; i--){
        int a = v[i].first, b = v[i].second;
        if(a >= already && b >= x-already-1) already++;     // "x-already-1" is the number of people we need to invite, which should smaller than b
    }
    return already >= x;        // invite the people as you can, don't return false immediately
}

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int>> v;
        v.reserve(n);
        for(int i=0; i<n; i++) {
            cin>>a>>b;
            v.push_back({a,b});
        }
        int low = 0, high = n;
        while(low<high){
            int mid = (low+high)/2 + 1;     // upper bound
            if(ok(v, mid)) low = mid;
            else high = mid-1;
        }
        cout<<low<<endl;
    }
    
    return 0;
}
