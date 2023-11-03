#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define MOD 998244353 
#define LL long long
int n, m;

LL pow_mod(LL a, LL b, LL p){//a的b次方求余p 
    LL ret = 1;
    while(b){
        if(b & 1) ret = (ret * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ret;
}
LL Fermat(LL a, LL p){//费马求a关于b的逆元 
        return pow_mod(a, p-2, p);
}

void solve(){
    cin>>n>>m;
    char c;
    for(int i = 1; i<=n-1; i++){
        cin>>c;
    }
}

signed main(){
    // int t;
    // cin>>t;
    // for(int i = 1; i <= t; i++){
    //     solve();
    // }
    cout<<Fermat(4, 11)<<'\n';
}