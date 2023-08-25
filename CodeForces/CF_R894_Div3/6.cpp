#include <bits/stdc++.h>
using namespace std;
#define MAXV (100 * 1'0000 + 1)
#define MAXN 101
#define INF 0x7fff'ffff;
bitset<MAXV> sum_mask; 
int f, w;
int n;
int a[MAXN];
int a_sum = 0;

int ceil(int x, int d){
    return (x + d - 1) / d;
}

void solve(){
    cin>>f>>w;
    cin>>n;
    a_sum = 0;
    for(size_t i = 1;i<=n;++i){
        cin>>a[i];
        a_sum += a[i];
    }
    sum_mask.set(a[1], true);
    for(size_t i = 2;i<=n;++i){
        sum_mask |= sum_mask<<(a[i]); // \sum_{i} S' + a_i
        sum_mask.set(a[i], true); // |S'| = 1
    }
    // S - > F \cup W
    int min_t = INF;
    for(size_t i = 1;i<MAXV;++i){
        if(sum_mask.test(i)){ 
            // \sum_{F} = i || \sum_{W} = i
            min_t = min(min_t, max(ceil(i, f), ceil(a_sum - i, w)));
            min_t = min(min_t, max(ceil(i, w), ceil(a_sum - i, f)));
        }
        //Initialization for next test
        sum_mask.set(i, false);
    }
    cout<<min_t<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(size_t i = 0;i<t;++i){
        solve();
    }
}