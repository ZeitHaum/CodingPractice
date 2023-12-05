#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n, k;
    cin >> n >> k;
    int g = __gcd(n, k);
    n = n / g;
    k = k / g;
    if(!(k & 1)){
        cout << -1 << "\n";
        return;
    }
    else{
        cout << n << "\n";
        for(int i = 0; i<= n-1; i++){
            if(i != 0) cout << " ";
            cout<<i*g + 1;
        }
        cout<<"\n";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    for(int i = 1; i<= T; ++i){
        solve();
    }
}   