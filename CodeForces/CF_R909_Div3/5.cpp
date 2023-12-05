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
void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int min_ind = -1;
    int min_v = INF; 
    for(int i = 1; i<= n; ++i){
        if(a[i] < min_v) min_v = a[i], min_ind = i;
    }
    bool ok = true;
    int ck = -1;
    int ck_ind = -1;
    for(int i = n - 1; i>=1; --i){
        if(a[i] > a[i + 1]){
            ck = a[i + 1], ck_ind = i;
            break;
        }
    }
    // int lck_ind = -1;
    for(int i = 1; i<= ck_ind; ++i){
        if(a[i] <= ck){
            ok = false;
            break;
        }
    }
    // if(lck_ind != -1){
    //     for(int i = lck_ind; i + 1<=ck_ind; ++i){
    //         if(a[i] > a[i + 1]) {
    //             ok = false;
    //             break;
    //         }
    //     }
    // }
    if(ok) cout << min_ind  - 1 << "\n";
    else cout << -1 << "\n";
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
/*
1
4
5 2 4 2
*/