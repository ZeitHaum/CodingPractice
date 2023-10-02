#include <bits/stdc++.h>
using namespace std;
#define MAXN 101
int n;
int s[MAXN];
int e[MAXN];
void solve(){
    cin>>n;
    bool check_1 = true;
    for(int i = 1; i<=n ; ++i){
        cin>>s[i] >> e[i];
        if(i>1) check_1 &= (e[i]>=e[1]? s[i]<s[1]: true);
    }   
    if(check_1) cout<<s[1]<<'\n';
    else cout<<"-1\n";
}

signed main(){
    int t;
    cin>>t;
    for(int i = 1; i <= t; ++i){
        solve();
    }
}