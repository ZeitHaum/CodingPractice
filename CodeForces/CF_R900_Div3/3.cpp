#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, k, x;
    cin>>n>>k>>x;
    int min_x = (k + 1) * k / 2;
    int max_x = (n - k + 1 +  n) * k / 2;
    if(x >= min_x && x <= max_x ) cout<<"YES\n";
    else cout<<"NO\n";  
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