#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x, int& fac){
    if(x<=2) return true;
    int r = min(x - 1, (int)sqrt(x)+1);
    for(size_t i = 2; i<=r;++i){
        if(x % i == 0) {
            fac = i;
            return false;
        }
    }
    return true;
}

void check_all(int x){
    int fac = -1;
    if(is_prime(x, fac)) cout<<-1<<'\n';
    else cout<<fac<<' '<<x - fac<<'\n';
}

void solve(){
    int l, r;
    cin>>l>>r;
    if(r<=3){cout<<"-1\n";}
    else if(r == 4) cout<<2<<' '<<2<<'\n';
    else{
        if(r-l>=1){
            if(!(r&1)) cout<<2<<' '<<r - 2<<'\n';
            else cout<<2<<' '<<r - 3<<'\n';
        }
        else check_all(l);
    }
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