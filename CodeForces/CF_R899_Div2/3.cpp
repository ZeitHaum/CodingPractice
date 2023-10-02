#include <bits/stdc++.h>
using namespace std;
#define MAXN 20'0001
#define int long long 
int n;
int da[MAXN + 1];
void solve(){
    cin>>n;
    int ans = 0;
    for(int i = 1; i<= n; i++){
        cin>>da[i];
    }
    for(int i = 3; i<=n; i++){
        if(da[i] > 0 ){
            ans += da[i];
        }
    }
    ans += max<int>({0, da[1], n>=2?da[1] + da[2] : 0});
    cout<<ans<<'\n';
}

signed main(){
    int t;
    cin>>t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}