// hash + suffix
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int t,n;
string s;

int main(){
    cin>>t;
    while(t--){
        unordered_map<char, int> right;
        unordered_set<int> left;
        cin>>n>>s;
        for(int i=0; i<n; i++) right[s[i]]++;
        int ans = right.size();
        for(int i=0; i<n; i++){
            right[s[i]]--;
            if(right[s[i]] == 0) right.erase(s[i]);
            left.insert(s[i]);
            ans = max(ans, int(left.size() + right.size()));
        }
        cout<<ans<<endl;
    }
    return 0;
}