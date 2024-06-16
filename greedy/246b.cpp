// analysis
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x, sum=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        sum += x;
    }
    if(sum%n == 0) cout<<n<<endl;
    else cout<<n-1<<endl;
    return 0;
}
