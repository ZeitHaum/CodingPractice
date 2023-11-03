#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n < 7 || n == 9) cout<<"NO\n";
    else{
        cout<<"YES\n";
        if( n % 3 == 1 ) cout<< 1 << " " << 2 << " " << n - 3 <<'\n';
        else if( n % 3 == 2) cout << 2 << " " << 5 << " "<< n - 7<<'\n';
        else cout<< 1 << " " << 4 << " "<< n - 5 <<'\n';
    }
}

signed main(){
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        solve();
    }
}