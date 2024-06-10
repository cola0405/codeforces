// easy

// character and integer
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    string s;
    cin>>n>>s;
    unordered_map<char, char> a;
    for(int i=1; i<=9; i++) cin>>a['0'+i];
    for(int i=0; i<n; i++){
        char c = s[i];
        if(a[c] > c) {
            for(int j=i; j<n; j++){         // it require every digits have to do the repalcement
                if(a[s[j]] < s[j]) break;   // so stop when f(c) < c
                s[j] = a[s[j]]; 
            }
            cout<<s<<endl;
            return 0;
        }
    }
    cout<<s<<endl;
    return 0;
}
