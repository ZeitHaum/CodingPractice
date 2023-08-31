#include <bits/stdc++.h>
using namespace std;

int n, a, q;

void solve(){
    cin>>n>>a>>q;
    int max_ = a, min_ = a, now_ = a;
    char c;
    for(size_t i = 1; i <= q; ++i){
        cin>>c;
        if(c=='+') max_ = min(max_ + 1, n), ++now_;
        else --now_;
        min_ = max(min_, now_);
    }
    if(min_ >= n) cout<<"YES\n";
    else if(max_ < n) cout<<"NO\n";
    else cout<<"MAYBE\n";
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