#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int n;
vector<string> ss;
vector<char> q;
unordered_map<char, int> in_deg;
unordered_map<char, vector<char>> g;

int main(){
    for(int i=0; i<26; i++) in_deg[(char)('a'+i)] = 0;  // initialize the in_deg
    cin>>n;
    ss.resize(n);
    for(int i=0;i<n;i++) cin>>ss[i];
    for(int i=0; i<n-1; i++){
        string s1 = ss[i];
        string s2 = ss[i+1];
        int j=0;
        while(j<s1.size() && j<s2.size() && s1[j]==s2[j]) j++;
        if(j == s1.size() || j == s2.size()) {      // this can't detect the conflict relation
            if(s1.size() > s2.size()) {
                cout<<"Impossible"<<endl;
                return 0;
            }
            continue;       // which means there is no useful relation from s1 and s2
        }
        g[s1[j]].push_back(s2[j]);
        in_deg[s2[j]]++;
    }
    
    // select the node whose in degree is zero
    for(auto& x : in_deg){
        if(x.second == 0) q.push_back(x.first);
    }
    vector<char> ans;
    while(q.size() > 0){
        char c = q.back();
        q.pop_back();
        ans.push_back(c);
        for(auto& v : g[c]){
            in_deg[v]--;
            if(in_deg[v] == 0) q.push_back(v);
        }
    }
    if(ans.size() != 26) cout<<"Impossible";
    else for(auto& c : ans) cout<<c;
    cout<<endl;
}