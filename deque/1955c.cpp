// greedy + deque

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long k;
        int n,x;
        cin>>n>>k;
        deque<int> dq;
        for(int i=0; i<n; i++){
            cin>>x;
            dq.push_back(x);
        }

        int ans = 0;
        while(k>0 && dq.size()>0){
            if(dq.size() == 1){
                if(k >= dq[0]) ans += 1;
                break;
            }
            int first = dq.front(), last = dq.back();
            int mn = min(first, last);
            if(k >= 2*mn){
                dq[0] -= mn; dq.back() -= mn;
                if(dq[0] == 0){
                    dq.pop_front();
                    ans++;
                }
                if(dq.back() == 0){
                    dq.pop_back();
                    ans++;
                }
            }
            else if ((k/2) + k%2 >= first){     // only the first got the chance
                ans++;
                break;
            }
            k -= 2*mn;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
