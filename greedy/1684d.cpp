// greedy + math anylyse

// it's always optimal to use all k skip
// but we can't easily select the k first damage, because of the bonus damage
// so the solution to solve it is consider the damge and bonus damage at the same time 
// let's see this equation: bi = ai - (n-1-i)
// for a single skip, it will cause the bonus damage to the remaining (n-1-i) elements in the right
// bi is actually represent the value of this skip 
// bi could be negative which means the bonus damage is greater than the damage of current trap
// so our greedy strategy is select the k-first bi to skip

// addition: you may consider that there may exist some skip after, and the right should not be (n-1-i)
// but let's think it in this way, we make the best choice in the worst situation, and it should be the optimal strategry

#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int t,n,k,damage;
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<pair<int,int>> b;
        vector<int> a;
        b.reserve(n);
        a.reserve(n);
        for(int i=0; i<n; i++){
            cin>>damage;
            b.push_back({damage-(n-1-i), i});   // bi
            a.push_back(damage);
        }
        sort(b.begin(), b.end());
        vector<int> skip(n, 0);     // flags
        int i=a.size()-1;
        while(k--){
            skip[b[i].second] = 1;
            i--;
        }
        ll ans = 0, bonus = 0;
        for(int i=0; i<n; i++){
            if(skip[i]) bonus++;
            else ans += a[i] + bonus;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
