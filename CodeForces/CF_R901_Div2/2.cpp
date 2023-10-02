#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 51
int n, m , k;
int da[MAXN];
int db[MAXN];
void solve(){
    cin>>n >> m >> k;
    int sum_da = 0, sum_db = 0;
    for(int i = 1; i<=n; i++) cin>>da[i];
    for(int i = 1; i<=n; i++) sum_da+=da[i];
    for(int i = 1; i<=m; i++) cin>>db[i];
    sort(da + 1, da + n + 1);
    sort(db + 1, db + m + 1);
    if(db[m] > da[1]) sum_da += (db[m] - da[1]);
    if(k & 1) cout<<sum_da<<'\n';
    else cout<<sum_da - max(da[n], db[m]) + min(da[1], db[1])<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i = 1;i<=t;i++){
        solve();
    }
}