#include <bits/stdc++.h>
using namespace std;

int x_ind[10];

void solve(){
    string x;
    cin>>x;
    for(size_t i = 0; i<x.size(); ++i){
        x_ind[x[i] - '0'] = i;
    }
    if(x_ind[3] > x_ind[7]) cout<<"73\n";
    else cout<<"37\n";
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