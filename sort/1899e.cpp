// anaylse

// always move the first element to the end
// then the element will keep moving to left, until finding a strictly smaller element

// the key is to find the reverse pair from right to left

#include <iostream>
#include <vector>
using namespace std;

int solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    int i = n-1;
    while(i > 0 && a[i] >= a[i-1]) i--;
    for(int j=0; j<i; j++){
        if(a[j] <= a[i]) return -1;     // the smaller element in the range take infinity operations
    }
    return i;
}
int main()
{
    int t;
    cin>>t;
    while(t--) cout<<solve()<<endl;
    return 0;
}
