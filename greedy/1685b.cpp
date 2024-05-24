// greedy

// the only matter factor is the ab and ba
// for them, the only matter factor is the segment like "ABABABAB..." or "BABABABA..."
// here is a thing we need know: for the segment "ABABAB" we get the substring to fit ba -- "BABA"

// so we need to extract these segments, sort them, and greedy use the shorter first
// you may consider that we can apply the segment according to it's type
// if it's end with 'B' just apply it to ab, if there do have extra characters, apply it to ba
// but this strategy is not optimal, because it may cause the waste

// consider this situation:
// now we only need 1 ba, but the segments order is "BABA" "BA"
// if we process in this order, it will cost the waste
// "BABA" can be only apply to ba, can't transform ot ab anymore

// but if we sort the segments "BA" "BABA"
// the "BA" can solve the need, and the "BABA" can transform to "AB"
// so sort before process of the data is optimal


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
        if(a+ab+ba != a_cnt){       // the probelm already said that s=a+b+ab+ba
            cout<<"NO"<<endl;
            continue;
        }
        vector<pair<int, char>> st = {{1, s[0]}};       // record the segments {length: end_character}
        for(int i=1; i<s.size(); i++){
            if(s[i] == st.back().second) st.push_back({1, s[i]});       
            else{
                auto x = st.back();
                st.pop_back();                      // record the segment like "ABABABAB", 
                st.push_back({x.first+1, s[i]});    // s[i] is the character in the end of this segement
            }
        }
        sort(st.begin(), st.end());
        int wait = 0;               // store the number of special pair, which can be "AB" or "BA"
        for(auto &[cnt, c]: st){
            if(cnt%2 == 0){
                if(c == 'A' && ba >= cnt/2) ba -= cnt/2;
                else if(c == 'B' && ab >= cnt/2) ab -= cnt/2;
                else wait += cnt/2 - 1;     // this segment must be transformed and waste the head and tail character
            }else{
                wait += cnt/2;              // odd length string "ABABA" it can be "ABAB" or "BABA"
            }
        }
        if(wait >= ab+ba) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
