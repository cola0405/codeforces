#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t,a,b,ab,ba;
string s;
int main()
{
    cin>>t;
    while(t--){
        cin>>a>>b>>ab>>ba>>s;
        int a_cnt = 0;
        for(int i=0; i<s.size(); i++) if(s[i] == 'A') a_cnt++;
        if(a+ab+ba != a_cnt){
            cout<<"NO"<<endl;
            continue;
        }
        vector<pair<char, int>> st = {{1, s[0]}};       // record the segments
        for(int i=1; i<s.size(); i++){
            if(s[i] == st.back().second) st.push_back({1, s[i]});
            else{
                auto x = st.back();
                st.pop_back();
                st.push_back({x.first+1, s[i]});
            }
        }
        sort(st.begin(), st.end());
        int wait = 0;
        for(auto &[cnt, c]: st){
            if(cnt%2 == 0){
                if(c == 'A' && ba >= cnt/2) ba -= cnt/2;
                else if(c == 'B' && ab >= cnt/2) ab -= cnt/2;
                else wait += cnt/2-1;
            }else{
                wait += cnt/2;
            }
        }
        if(wait >= ab+ba) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
