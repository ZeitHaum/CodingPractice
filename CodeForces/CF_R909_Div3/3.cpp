#include <bits/stdc++.h>
using namespace std;
// #define DEBUG

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n;
#ifndef DEBUG
#define MAXN 20'0001
#endif
#ifdef DEBUG
#define MAXN 21
#endif
#define INF 1'0000'0000'1
int a[MAXN];
int dp[MAXN];
void solve(){
    cin>>n;
    for(int i = 1; i<=n; ++i){
        cin >> a[i];
    }

    for(int i = 1; i<=n; ++i){
        if(i == 1) dp[i] = a[i];
        else{
            if((a[i] & 1) ^ (a[i - 1] & 1)){
                dp[i] = max(a[i], dp[i - 1] + a[i]);
            }
            else dp[i] = a[i];
        }
    }
    cout << *max_element(dp + 1, dp + n + 1)  << "\n";
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