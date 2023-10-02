#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c;
    cin>>a>>b>>c;
    cout << (abs(a - b) + 2*c - 1)/ (2*c)<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(size_t i = 0;i<t;++i){
        solve();
    }
}