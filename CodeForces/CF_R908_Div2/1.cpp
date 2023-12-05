#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

inline void solve(){
    int n;
    cin>> n;
    string s;
    cin>>s;
    if(s.back() == 'A') cout << "A\n";
    else cout <<"B\n";
}

signed main(){
    fast_io();
    int t;
    cin>>t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}