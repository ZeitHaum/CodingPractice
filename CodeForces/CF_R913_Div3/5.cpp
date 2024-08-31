#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int int_split3(int x){
    return (x + 2) * (x + 1) / 2;
}


void solve(){
    int n;
    cin >> n;
    int ans = 1;
    while(n != 0){
        ans *= int_split3(n % 10);
        n = n/10;
    }
    cout << ans << "\n";
}

signed main(){
    #ifndef DEBUG
    fast_io();
    #endif
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        solve();
    }
}