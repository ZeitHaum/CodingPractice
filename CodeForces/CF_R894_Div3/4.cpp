#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXM (20'0000'0000ll)

void solve(){
    int n;
    cin>>n;
    int l = 0l, r = MAXM;
    while(r - l>1){
        int mid = l + (r - l)/2;
        if(mid*(mid-1)> 2*n){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout<< n + l - l*(l-1)/2<<'\n';
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