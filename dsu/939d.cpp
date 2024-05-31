#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, char> par;
char root(char x){
    if(par[x] == x) return x;
    par[x] = root(par[x]);
    return par[x];
}
int main()
{
    int n;
    string s1,s2;
    vector<string> ans;
    cin>>n>>s1>>s2;
    for(int i=0; i<26; i++) par[char('a'+i)] = char('a'+i);
    for(int i=0; i<n; i++){
        if(s1[i] != s2[i] && root(s1[i]) != root(s2[i])){
            par[root(s1[i])] = root(s2[i]);
            ans.push_back(string(1,s1[i]) + " " + string(1,root(s2[i])));
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<endl;
    return 0;
}
