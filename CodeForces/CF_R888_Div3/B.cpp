#include <bits/stdc++.h>
using namespace std;

#define MAXN 200'001
int da[MAXN];
int sort_da[MAXN];

void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>da[i];
        sort_da[i] = da[i];
    }
    sort(da+1, da+n+1);
    int ans = true;
    for(int i = 1;i<=n;i++){
        if(((da[i] + sort_da[i]) & 1) != 0){
            ans = false;
            break;
        }
    }
    if(ans){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

signed main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}