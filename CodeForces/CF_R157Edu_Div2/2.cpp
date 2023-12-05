#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 201
int da[MAXN];

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve(){
    int n;
    cin>>n;
    for(int i = 1; i<=2 * n; ++i){
        cin>>da[i];
    }
    sort(da + 1, da + 2 * n + 1);
    cout << da[2 * n] - da[1] - (da[n + 1] - da[n]) << '\n';
    for(int i = 1; i<= n; i++){
        cout<< da[i] << " "<< da[i + n] << "\n";
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