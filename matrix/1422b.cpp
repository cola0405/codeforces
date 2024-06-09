// 2d palindrome

// x1 = a[i][j], x2 = a[n-1-i][j], x3 = a[n-1-i][m-1-j], x4 = a[i][m-1-j];
// there do have certain pattern between these 4 numbers
// 1 2 3 4
// 5 6 7 8
// 9 10 11 18

// x1=1, x2=9, x3=18, x4=4
// these 4 number should be the same to fit the condition of palindrome
// the optimal way to dealing with this is to find the median of these 4 number
// sort them, find the middle number, if the length is even, then find the average of middle two elements



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n);
        for(int i=0; i<n; i++) {
            a[i].resize(m);
            for(int j=0; j<m; j++) cin>>a[i][j];
        }
        long long ans = 0;
        for(int i=0; i<=n/2; i++){                  // to calculate the middle line of odd lines
            if(i == n/2 && n%2 == 0) continue;
            for(int j=0; j<=m/2; j++){              // to calculate the middle line of odd columns 
                if(j == m/2 && m%2 == 0) continue;     
                int x1 = a[i][j], x2 = a[n-1-i][j];
                int x3 = a[n-1-i][m-1-j], x4 = a[i][m-1-j];
                vector<int> v = {x1, x2, x3, x4};
                sort(v.begin(), v.end());
                int mid = (v[1]+v[2])/2;        // median
                if(i == n-1-i) ans += abs(x1-mid) + abs(x4-mid);        // to calculate the middle line of odd lines
                else if(j == m-1-j) ans += abs(x1-mid) + abs(x2-mid);   // to calculate the middle line of odd columns
                else ans += abs(x1-mid) + abs(x2-mid) + abs(x3-mid) + abs(x4-mid);
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
