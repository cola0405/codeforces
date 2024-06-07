#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if(n == 1){
        cout<<1<<endl;
        return 0;
    }
    if(m > n/2){            // determine which side got more numbers
        cout<<m-1<<endl;
    }else{
        cout<<m+1<<endl;
    }
    return 0;
}
