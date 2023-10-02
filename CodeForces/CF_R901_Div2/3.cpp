#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int x, int y){
    if(x == 1) return y - 1;
    else if(x == 0) return 0;
    int g = __gcd(x - 1, y);
    return g * f(x / g, y / g) + y - 1;
}

void solve(){
    int n, m;
    cin>>n >>m;
    int g = __gcd(n, m);
    if(__builtin_popcount((size_t)(m /g)) != 1){
        cout<<"-1\n";
        return;
    }
    else{
        n = n % m;
        cout<<g * (f(n/g, m/g)) << "\n";
    }
}

signed main(){
    int t;
    cin>>t;
    for(int i = 1;i<=t;i++){
        solve();
    }
}