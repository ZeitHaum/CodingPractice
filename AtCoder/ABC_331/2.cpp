#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

signed main(){
    #ifndef DEBUG
    fast_io();
    #endif
    int N, S, M, L;
    cin >> N >> S >> M >> L;
    vector<int> dp(101);
    for(int i = 1; i<=6; ++i){
        dp[i] = min({S, L, M});
    }
    dp[7] = min({dp[1] + S, M, L});
    dp[8] = min({dp[2] + S, M, L});
    dp[9] = min({dp[3] + S, dp[1] + M, L});
    dp[10] = min({dp[3] + S, dp[2] + M, L});
    dp[11] = min({dp[3] + S, dp[3] + M, L});
    dp[12] = min({dp[3] + S, dp[4] + M, L});
    for(int i = 13; i<= N; ++i){
        dp[i] = min({dp[i - 6] + S, dp[i - 8] + M, dp[i - 12] + L});
    }
    cout << dp[N] << "\n";
}