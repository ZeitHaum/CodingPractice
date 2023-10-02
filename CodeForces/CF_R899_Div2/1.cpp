#include <bits/stdc++.h>
using namespace std;
#define MAXN 101

int da[MAXN];
int db[MAXN];
int n;
void solve(){
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>da[i];
    }
    int b_ptr = 1;
    int now_in = 1;
    for(int i = 1; i<=1001; i++){
        if(b_ptr > n) break;
        if(now_in == da[b_ptr]) now_in ++;
        else db[b_ptr++] = now_in++;
    }
    cout<<db[n]<<'\n';
}

signed main(){
    int t;
    cin>>t;
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    for(int i = 1; i<=t; i++){
        solve();
    }
}
