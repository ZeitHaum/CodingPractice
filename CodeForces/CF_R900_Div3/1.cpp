#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 101
int da[MAXN];

void solve(){
    int n;
    int k;
    cin>>n>>k;
    bool ck = false;
    for(int i = 1; i<= n; i++){
        cin>>da[i];
        ck |= (da[i] == k);
    }
    if(ck) cout<<"YES\n";
    else cout<<"No\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        solve();
    }
}