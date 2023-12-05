#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve(){
    int tmp;
    cin >> tmp;
    if(tmp % 3 == 0) cout << "Second\n";
    else cout << "First\n"; 
}

signed main(){
    fast_io();
    int t;
    cin>> t;
    for(int i = 1; i<=t; ++i){
        solve();
    }
}