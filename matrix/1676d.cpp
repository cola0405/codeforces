#include<iostream>
using namespace std;

int t,n,m;
int a[201][201];

int d[4][2] = {{-1,-1}, {-1,1}, {1,1}, {1,-1}};
int four(int x, int y){
    int sum = 0;
    for(int i=0; i<4; i++){
        int nx = x;
        int ny = y;
        while(nx>=0 && nx<n && ny>=0 && ny<m){
            nx += d[i][0];          // exclude a[x][y]
            ny += d[i][1];
            if(nx<0 || nx>=n || ny<0 || ny>=m) break;
            sum += a[nx][ny];
        }
    }
    return sum;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) cin>>a[i][j];
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                int res = a[i][j] + four(i,j);
                ans = max(ans, res);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}