#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    for(int i = 1; i<=n/2; i++){
        if(i!=1) cout<<" ";
        cout<<3*(i)<<" "<<3*i + 1;
    }
    if(n & 1) cout<<" "<<3*(n/2 + 1);
    cout<<"\n";
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