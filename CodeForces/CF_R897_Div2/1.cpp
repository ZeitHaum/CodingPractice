#include <bits/stdc++.h>
using namespace std;
#define MAXN 4'0001

int n;
pair<int, int> da[MAXN];
int ans[MAXN];

void solve(){
    cin>>n;
    for(size_t i = 1; i<= n; ++i){
        cin>>da[i].first;
        da[i].second = i;
    }
    sort(da+1, da+n+1);
    for(size_t i = 1; i<= n; ++i){
        ans[da[i].second] = n + 1 - i;
    }
    for(size_t i = 1; i<= n; ++i){
        if(i != 1) cout<<' ';
        cout<<ans[i];
    }
    cout<<'\n';
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