#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
int a[MAXN];

void solve(){
    int x, y, n;
    cin>> x >> y >> n;
    if(y - x < n*(n-1)/2){
        cout<<"-1\n";
    }
    else{
        a[1] = x;
        a[n] = y;
        int now = y - x;
        for(int i = n-1; i>=3;i--){
            a[i] = a[i+1] - (n - i);
            now -= (n - i);
        }
        a[2] = x + now - (n - 2);
        for(size_t i = 1; i<=n; ++i){
            if(i!=1) cout<<' ';
            cout<<a[i];
        }
        cout<<'\n';
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