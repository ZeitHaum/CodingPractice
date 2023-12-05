#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 5'001
inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int P[MAXN];
double pow9[MAXN];
double dp[MAXN];

signed main(){
    fast_io();
    int N;
    cin>>N;
    for(int i = 1; i<= N; i++){
        cin >> P[i];
    }
    double now = 1.0;
    for(int i = 0; i<=N; i++){
        pow9[i] = now;
        now = now * (double)0.9;
    }
    for(int k = 0; k<= N; k++){
        dp[k] = 0;
    }
    for(int i = 1; i<=N; i++){
        for(int k = N; k >= 1; k--){
            if(k > i) continue;
            dp[k] = max(dp[k], dp[k - 1] * 0.9 + (double)P[i]);
        }
    }
    double ans = -1200.0;
    double fenmu = 1.0;
    double fenzi = 0;
    for(int k = 1; k <= N; k++){
        fenzi = dp[k];
        ans = max(ans, fenzi / fenmu - 1200.0 / sqrt(k));
        fenmu += pow9[k];
    }
    cout << fixed << setprecision(12)<< ans << '\n';
}