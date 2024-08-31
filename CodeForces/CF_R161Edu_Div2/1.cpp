#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 20'0001

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve(){
    string a, b, c;
    int n;
    cin >> n;
    cin >> a >> b >> c;
    for(int i = 0; i<n; ++i){
        if(a[i] == b[i]){
            if(c[i] != a[i]){
                cout << "YES\n";
                return;
            }
        }
        else{
            if(c[i] != a[i] && c[i] != b[i]){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

signed main(){
    fast_io();
    int t;
    cin >> t;
    for(int i = 0; i<t; ++i){
        solve();
    }
}
/*
1
10
mathforces
luckforces
adhoccoder
*/