#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, x, y;
int calck(){
    return (n * __gcd(x, y)) / (x * y);
}

void solve(){
    cin>>n >> x >> y;
    int ans = 0;
    int k = calck();
    int kx = n / x - k;
    int ky = n / y - k;
    ans = (kx * (n + n + 1 - kx) / 2 ) - (ky * (1 + ky) / 2);
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