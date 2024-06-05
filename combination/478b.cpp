#include <iostream>
using namespace std;

int main()
{
    long long n,m,mx,mn;
    cin>>n>>m;
    mx = max(0ll, (n-(m-1))*(n-(m-1)-1)/2);     // n*(n-1)/2
    mn = (n/m)*(n/m-1)/2 * m;
    mn += n%m * (n/m);              // remainer
    cout<<mn<<" "<<mx<<endl;
    return 0;
}
