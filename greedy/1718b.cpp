// greedy + heap

// block is 'aaaaa' segment with the same character
// the fib-string shouldn't have the adjacent block with the same character
// 'a aa' is not allowed  

// transform the problem, consider mapping from [1,1,2,3,5] to ci
// consider f[i] will map which ci

// check from the largest f[i] to smaller, finding if there exist enough block
// it's always optimal to pick up the most block first

// prove (try to construct a test case)
// [1,1,2,3,5]
// assuming that for largest f[i] = 5
// we choose the middle block with size 7 (not the most)
//    ...   5
//  1 1 2 3 5
//  assuming that there exist a element(>=5) on the right
//    ...   5 (5)
//  1 1 2 3 5
//          i
// for the extra (5), we need to settle it down 
// using the skipping and greedy way: "pickup" = f[i-1] + f[i-3] + f[i-5] + ... + f[i-k] (i-k>=0)
// but actually 5 is f[i] = f[i-1] + f[i-2] = f[i-1] + (f[i-3]+f[i-4])
// 5 = f[i] = f[i-1] + f[i-3] + f[i-5] + f[i-6] is always greater than "pickup"
// so the pickup is always not enough to settle the extra 5
// it's always optimal to pick up the most block first not the middle block

#include <iostream>
#include<algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int t,k,x,remain,total,sum=2;
vector<int> f={1,1};

void build_fib(){
    while(sum < total){
        f.push_back(f[f.size()-1] + f[f.size()-2]);
        sum += f.back();
    }
}

int get_back(){     // find the fit larget fib number
    int i=0, tt=0;
    while(tt < total){
        tt += f[i];
        i++;
    }
    if(tt != total) return -1;      // current test case can't fit the fib numbers
    return i-1;
}

bool solve(){
    total = 0;
    priority_queue<pair<int,int>> pq;   // (cnt, i) "i" represent the type
    cin>>k;
    for(int i=0;i<k;i++) {
        cin>>x;
        total += x;
        pq.push(make_pair(x,i));
    }
    build_fib();
    int last = -1;
    int back = get_back();
    if(back == -1) return false;
    for(int i=get_back(); i>=0; i--){
        if(pq.empty()) return false;
        auto top = pq.top();
        pq.pop();
        if(f[i] > top.first) return false;       // the longest block can't work out
        if(top.second == last){     // make sure the adjacent blocks using the different character
            if(pq.empty()) return false;
            auto top2 = pq.top();
            pq.pop();
            if(top2.first < f[i]) return false;  // no other type of block can work out
            pq.push(top);
            top = top2;         // use top2 and put back the top block
        }
        remain = top.first-f[i];
        if(remain > 0) pq.push(make_pair(remain, top.second));
        last = top.second;
    }
    return true;
}

int main()
{
    cin>>t;
    while(t--){
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}