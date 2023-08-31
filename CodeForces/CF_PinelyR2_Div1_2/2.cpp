#include <bits/stdc++.h>
using namespace std;
#define MAXN 10'0002

int n;
int p[MAXN];
int p_ind[MAXN];

void solve(){
    cin>>n;
    for(size_t i = 1; i <= n; ++i){
        cin>>p[i];
        p_ind[p[i]] = i;
    }
    int now = 1;
    int ans = 0;
    while(now <= n){
        int last = p_ind[now];
        ++now;
        for(;now <= n; ++now){
            if(p_ind[now] > last) last = p_ind[now];
            else break;
        }
        if(now <= n)ans++;
    }
    cout<<ans<<'\n';
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