#include <bits/stdc++.h>
using namespace std;

int da[101];

void solve(){
    int n, x;
    cin >> n >> x;
    for(int i = 1; i<=n; ++i){
        cin >> da[i];
    }
    int ans = da[1];
    for(int i = 2; i<=n;++i){
        ans = max(ans, da[i] - da[i - 1]);
    }
    ans = max(ans, 2 *(x - da[n]));
    cout << ans << '\n';
}

signed main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        solve();
    }
}