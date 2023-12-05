#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 20'0001
int da[MAXN];
int dp[MAXN];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i<=n; ++i){
        cin >> da[i];
    }
    dp[1] = da[1] - 1;
    for(int i = 2; i<=n; ++i){
        if(da[i - 1] >= da[i]) dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] + (da[i] - da[i - 1]);
    }
    cout << dp[n] << '\n';
}

signed main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        solve();
    }
}