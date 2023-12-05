#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n, q;
#define MAXN 501
int d[MAXN];
void solve(){
    cin >> n >> q;
    for(int i = 1; i<= n-1; i++){
        cout << i << " " << i + 1 << "\n";
    }
    int last_d = n - 1;
    for(int i = 1; i<= q; ++i){
        cin >> d[i];
        if(n - d[i] == last_d) cout << "-1 -1 -1\n";
        else cout<< n << " "<< last_d << " " << n - d[i] << '\n';
        last_d = n - d[i];
    }
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