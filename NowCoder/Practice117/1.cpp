#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 20'0001
int da[MAXN];
void solve(){
    int n;
    cin>>n;
    for(int i = 1; i<=n; ++i){
        cin>>da[i];
    }
    sort(da + 1, da + n + 1);
    int sum = 0;
    bool all_same = true;
    for(int i = 2; i<= n - 1; ++i){
        sum += da[i];
        if(da[i]!=da[2] && !all_same) all_same = false;
    }
    if(da[n] != da[2]) all_same = false;
    cout<<sum + (int)(true ^ all_same)<<'\n';
}

signed main(){
    int T;
    cin>>T;
    for(int i = 1; i<= T; ++i){
        solve();
    }
}   