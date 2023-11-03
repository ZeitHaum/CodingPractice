#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define MOD 998244353
#define LL long long 
int n, m;
#define MAXN 30'0001
char s[MAXN];
LL pow_mod(LL a, LL b, LL p){
    LL ret = 1;
    while(b){
        if(b & 1) ret = (ret * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ret;
}
LL Fermat(LL a, LL p){
    return pow_mod(a, p-2, p);
}

void solve(){
    cin>>n>>m;
    int mul3 = 1;
    for(int i = 2; i<= n; i++){
        cin>>s[i - 1];
        if(s[i - 1] == '?' && i >= 3) mul3 = (mul3 * (i - 2)) % MOD;
    }
    int now_ans = (s[1] == '?')? 0 : mul3;
    cout<<now_ans<<'\n';
    for(int i = 1; i<=m; i++){
        int ti;
        char tc;
        cin>>ti>>tc;
        if(ti >= 3 && s[ti] == '?' && tc != '?') mul3 = (mul3 * Fermat(ti - 1, MOD)) % MOD;
        if(ti >= 3 && s[ti] != '?' && tc == '?') mul3 = mul3 * (ti - 1) % MOD;
        s[ti] = tc;
        if(s[1] == '?') cout<<0<< '\n';
        else cout<<mul3 << '\n';
    }
}

signed main(){
    int t;
    t = 1;
    for(int i = 1; i <= t; i++){
        solve();
    }
}