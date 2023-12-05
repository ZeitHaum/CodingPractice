#include <bits/stdc++.h>
using namespace std;
// #define DEBUG

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int n, m;
#ifndef DEBUG
#define MAXN 20'0001
#endif
#ifdef DEBUG
#define MAXN 21
#endif
#define MAXM 6
char S[MAXN];
char T[MAXM];
bool dp[MAXN][MAXM];
signed main(){
    #ifndef DEBUG
    fast_io();
    #endif
    cin >> n >> m;
    for(int i = 1; i<=n; ++i){
        cin >> S[i];
    }
    for(int i = 1; i<=m; ++i){
        cin >> T[i];
    }
    for(int j = 1; j<=m; ++j){
        if(j == 1) dp[1][j] = S[j] == T[j];
        else dp[1][j] = false; 
    }
    for(int i = 2; i<=n; ++i){
        for(int j = 1; j <=m; ++j){
            dp[i][j] = false;
            if(S[i] != T[j]){
                continue;
            }
            if(j > 1 && S[i - 1] == T[j - 1]){
                dp[i][j] |= dp[i - 1][j - 1]; 
            }
            if(j > 1 && S[i - 1] == T[m]){
                dp[i][j] |= dp[i - 1][m];
            }
            else if(j == 1){
                for(int k = 1; k<=m; k++){
                    dp[i][j] |= dp[i - 1][k];
                }
            }
        }
    }
    if(dp[n][m]) cout << "Yes\n";
    else cout << "No\n";
}