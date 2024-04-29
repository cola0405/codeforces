#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    char x1,x2;
    int y1,y2;
    cin>>x1>>y1>>x2>>y2;
    int ans = 0;
    vector<string> moves;
    while(x1!=x2 || y1!=y2){
        string s;
        if(x1<x2){
            x1++;
            s.push_back('R');
        }else if(x1>x2){
            x1--;
            s.push_back('L');
        }
        if(y1<y2){
            y1++;
            s.push_back('U');
        }else if(y1>y2){
            y1--;
            s.push_back('D');
        }
        ans++;
        moves.push_back(s);
    }
    cout<<ans<<endl;
    for(auto s: moves){
        cout<<s<<endl;
    }
}