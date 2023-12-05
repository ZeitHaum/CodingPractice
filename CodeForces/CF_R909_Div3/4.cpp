#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n;
#define MAXN 20'0001
int a[MAXN];
map<int, int > bk;

inline int get_bk(int x){
    if(bk.find(x) == bk.end()) return 0;
    else return bk[x];
}

inline void add_bk(int x){
    if(bk.find(x) == bk.end()) bk[x] = 1;
    else  ++bk[x];
}

inline int calc_cnt(int c){
    if(c <=1) return 0;
    else return c * (c - 1) / 2;
}

void solve(){
    cin >> n;
    bk.clear();
    for(int i = 1; i<=n; ++i){
        cin >> a[i];
        add_bk(a[i]);
    }
    int ans = calc_cnt(get_bk(1) + get_bk(2));
    for(auto& it: bk){
        if(it.first == 1 || it.first == 2) continue;
        else ans += calc_cnt(it.second);
    }
    cout << ans << '\n';
}

signed main(){
    #ifndef DEBUG
    fast_io();
    #endif
    int t;
    cin>> t;
    for(int i = 1; i<=t; ++i){
        solve();
    }
    #ifdef DEBUG
    assert(0);
    #endif
}