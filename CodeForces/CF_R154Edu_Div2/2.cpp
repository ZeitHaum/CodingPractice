#include <bits/stdc++.h>
using namespace std;

void solve(){
    string a, b;
    cin>>a>>b;
    int end_0 = 0;
    int ck = false;
    for(size_t i = 0; i<a.size(); ++i){
        if(a[i] == '0' && b[i] == '0') end_0 = i;
        else if(a[i]=='1' && b[i] == '1' && end_0 == i - 1){
            ck = true;
            break;
        }
    }
    if(ck) cout<<"YES\n";
    else cout<<"NO\n";
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