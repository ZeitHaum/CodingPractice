#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 101
int a, b, n; 
int da[MAXN];
void solve(){
    cin>>a>>b>>n;
    int ans = b - 1;
    for(int i = 1; i<=n; i++){
        cin>>da[i];
        ans += min(da[i], a - 1);
    }
    ++ans;
    cout<<ans<<'\n';
}

signed main(){
    int t;
    cin>>t;
    for(int i = 1;i<=t;i++){
        solve();
    }
}