#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 30'0001
int n;
int da[MAXN];
multiset<int> ans_j;

inline void init(){
    ans_j.clear();
    ans_j.insert(da[1]);
    for(int i = 2; i<=n; i++){
        ans_j.insert(da[i] + i - 1);
    }
}

inline void change(int x, int to_x){
    auto it = ans_j.find(x);
    assert(it != ans_j.end());
    ans_j.erase(it);
    ans_j.insert(to_x);
}

void solve(){
    cin >> n; 
    for(int i = 1; i<=n; ++i){
        cin >> da[i];
    }
    init();
    int ans = *ans_j.rbegin();
    for(int i = 2; i<=n; ++i){
        //move
        change(da[i - 1], da[i - 1] + n - (i - 1));
        change(da[i] + i - 1, da[i]);
        ans = min(ans, *ans_j.rbegin());
    }
    cout << ans << '\n';
}

signed main(){
    int t;
    t = 1;
    for(int i = 1; i <= t; ++i){
        solve();
    }
}