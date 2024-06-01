#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<char> st;
    string s;
    cin>>s;
    for(auto c: s){
        if(st.size()>0 && c == st.back()) st.pop_back();
        else st.push_back(c);
    }
    if(st.size() > 0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}
