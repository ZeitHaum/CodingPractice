#include <bits/stdc++.h>
using namespace std;
#define MAXN 101
#define MAXV 401
int n;
int da[MAXN];
int s[MAXN];

void solve(){
    cin>>n;
    int k = MAXV;
    for(size_t i = 1; i<=n; ++i){
        cin>>da[i];
        cin>>s[i];
        k = min(k, da[i] + (s[i] - 1)/2);
    }
    cout<<k<<'\n';
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