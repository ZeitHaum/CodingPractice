#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG
#undef DEBUG
#ifndef DEBUG
#define MAXN 20'0001
#endif
#define s_get(i) s[i - 1]
#ifdef DEBUG
#define MAXN 21
#endif
int n, k;
string s;
int l[MAXN];
int r[MAXN];
bitset<MAXN> mask;
char t[MAXN];
void solve(){
    cin>>n>>k;
    cin>>s;
    mask&= 0;
    for(int i = 1; i<=k; i++){
        cin>>l[i];
    }
    for(int i = 1; i<=k; i++){
        cin>>r[i];
    }
    int q, x;
    cin>>q;
    for(int j = 1; j<=q; j++){
        cin>>x;
        int i = lower_bound(r+1, r+k+1, x) - r;
        #ifdef DEBUG
        cout<<i<<",";
        #endif
        mask.flip(min(x, l[i] + r[i] - x));
        mask.flip(max(x, l[i] + r[i] - x));
    }
    #ifdef DEBUG
    cout<<mask<<'\n';
    #endif
    int now_state = 0;
    for(int i = 1; i<=k; i++){
        for(int j = l[i];j<=r[i];j++){
            if(j < l[i] + r[i] - j && mask.test(j)) now_state ^=1;
            if(now_state) t[j] = s_get(l[i] + r[i] - j);
            else t[j] = s_get(j);
            if(j > l[i] + r[i] - j && mask.test(j)) now_state ^=1;
        }
    }
    for(int i = 1; i<=n; i++){
        cout<<t[i];
    }
    cout<<'\n';
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        solve();
    }
}