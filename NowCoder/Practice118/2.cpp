#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
#define MAXN 100'0001
#define int long long
signed main(){
    fast_io();
    int n, k;
    cin>>n >> k;
    uint64_t ans = 0LL;
    int tmp = 0;
    uint64_t sq_gcd = 0LL;
    for(int i = 1; i<= n; ++i){
        cin >> tmp;
        int gt = __gcd(tmp, k);
        ans += gt;
        sq_gcd += __gcd(tmp * tmp, k) /;
    }
    ans = ans * (n - 1) + sq_gcd;
    cout << ans << '\n';
}