#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MAXN 1001
#define N_INF ((int)(-1E9 - 7))
int da[MAXN];
int db[MAXN];
int dp[MAXN][MAXN][3];

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

signed main(){
    fast_io();
    int n, x;
    cin >> n >> x;
    for(int i = 1; i<= n; i++){
        cin >> da[i];
    }
    for(int i = 1; i<= n; i++){
        cin >> db[i];
    }
    for(int i = 0; i<= x; i++){
        dp[0][i][0] = 0;
        dp[0][i][1] = N_INF;
        dp[0][i][2] = N_INF;
    }
    for(int i = 1; i<= n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j][0] = max({dp[i - 1][j][0], dp[i - 1][j][1], dp[i - 1][j][2]});
            if(j >= da[i]) dp[i][j][1] = max({dp[i - 1][j - da[i]][0] + db[i], dp[i - 1][j - da[i]][1] + db[i], dp[i - 1][j - da[i]][2] + db[i]});
            else dp[i][j][1] = N_INF;
            if(j >= da[i] / 2) dp[i][j][2] = dp[i - 1][j - da[i]/2][1] + db[i];
            else dp[i][j][2] = N_INF;
        }
    }
    cout << max<int>({dp[n][x][0], dp[n][x][1], dp[n][x][2]}) << '\n';
}