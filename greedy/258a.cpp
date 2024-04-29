// analyse the test case + classic
#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    bool flag = true;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '0'){
            s.erase(i, 1);
            flag = false;
            break;
        }
    }
    if(flag) s.pop_back();
    cout << s << endl;
    return 0;
}