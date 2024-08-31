#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 30'0001

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int a[MAXN];
map<int, int> buk;
#define add(x) if(buk.find(x) == buk.end()) { \
    buk[x] = 1;\
}\
else{\
    buk[x]++;\
}

#define get(x) (buk.find(x) == buk.end()?0 : buk[x])
void solve(){
    buk.clear();
    int n;
    cin >> n;
    for(int i = 1; i<=n; ++i){
        cin >> a[i];
        add(a[i]);
    }
    int ans = 0;
    int acc_sum = 0;
    for(auto& p : buk){
        int pc = p.second;
        if(pc >= 2){
            ans += (pc * (pc - 1) / 2 * acc_sum);
        }
        acc_sum += pc;
        if(pc >= 3){
            ans += (pc * (pc - 1) * (pc - 2) / 6);
        }
    }
    cout << ans << '\n';
}

signed main(){
    fast_io();
    int t;
    cin >> t;
    for(int i = 0; i<t; ++i){
        solve();
    }
}