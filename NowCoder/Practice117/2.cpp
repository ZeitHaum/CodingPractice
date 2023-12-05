#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int l, r, k;
    cin>> l >> r >> k;
    if(k == 0){
        cout << (r - l + 1) % 2 << '\n';
        return ;
    }
    int odd_cnt = 0;
    if((r - l + 1) & 1) {
        if(l & 1) odd_cnt = (r - l + 1) / 2 + 1;
        else odd_cnt = (r - l + 1) / 2;
    }
    else odd_cnt = (r - l + 1) / 2;
    // cerr << odd_cnt<<'\n';
    cout<<odd_cnt % 2<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    for(int i = 1; i<= T; ++i){
        solve();
    }
}   