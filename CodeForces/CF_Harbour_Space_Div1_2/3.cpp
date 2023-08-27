#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001
int ans[MAXN];

void solve(){
    int x;
    cin>>x;
    bitset<32> bx(x);
    int cnt = 0;
    ans[0] = x;
    while(x!=1){
        while(bx.count()!=1){
            int le = bx._Find_first();
            x -= 1<<le;
            bx.set(le, false);
            ans[++cnt] = x;
            // cerr<<bx<<','<<x<<","<<le<<'\n';
        }
        x>>=1;
        ans[++cnt] = x;
    }
    cout<<cnt + 1<<'\n';
    for(size_t i = 0; i<=cnt; ++i){
        if(i!=0) cout<<' ';
        cout<<ans[i];
    }
    cout<<'\n';
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