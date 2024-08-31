#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve(){
    char col;
    int row;
    cin >> col >> row;
    for(int i = 1; i<=8; ++i){
        if(i != row) cout << col << i << "\n";
    }
    for(int i = 1; i<=8; ++i){
        if(char('a' - 1 + i) != col) cout << char('a' - 1 + i) << row << "\n";
    }
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