#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve(){
    int x, y, k;
    cin>>x>>y>>k;
    if(x >= y){
        cout << x << '\n';
    }
    else{
        if(y > x + k) cout<< y + (y - x - k) << '\n';
        else cout<< y << '\n';
    }
}

signed main(){
    fast_io();
    int t;
    cin>>t;
    for(int i = 1; i<=t; ++i){
        solve();
    }
}