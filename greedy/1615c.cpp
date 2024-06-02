// analyse

// observation: do the operation on different position i and j will only exchange these two value
// if the number of 1 is the same for s1 and s2, we only need to swap the 1 to the correct position
// 1 swap need 2 operation
// 1 swap fix 2 difference, so k difference need k/2 swap and k/2 *2 = k operation

// but there do have the situation that the number of 1 is different for s1 and s2
// observation: a single operation can reverse the type
// so we can compare the number of 0 from s1 and s2 after a operation
// if(1 + (n-cnt1) == cnt2) we can also find a solution to finish the task

// and there do have two options: 1.(11) 2.(10)
// in this situation, ans = 1 + new_diff
// for option 1: new_diff = same-1 = (n-diff)-1, ans = n-diff
// for option 2: new_diff = same+1 = (n-diff)+1, ans = n-diff+2
// for greedy, we will choose (11) optimally
// but what if there do not exist (11) ? it's interesting
// when there is no (11), the pair are all (10) or (01)
// if the number of 1 is the same, we don't need to consider the two options
// if the number of 1 is different, and there only exist (10) and (01) the swap will not work
// so we only need to consider the situion with (11) -- ans = min(ans, n-diff);
#include <iostream>
using namespace std;

int t,n;
int main()
{
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>n>>s1>>s2;
        int cnt1=0, cnt2=0, diff=0;
        for(int i=0; i<n; i++){
            if(s1[i] == '1') cnt1++;
            if(s2[i] == '1') cnt2++;
            if(s1[i] != s2[i]) diff++;
        }
        int ans = INT_MAX;
        if(cnt1 == cnt2) ans = diff;    
        if(1+(n-cnt1) == cnt2) ans = min(ans, n-diff);      // after reverse, the "diff" and "same" will swap
        if(ans == INT_MAX) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    
    return 0;
}
