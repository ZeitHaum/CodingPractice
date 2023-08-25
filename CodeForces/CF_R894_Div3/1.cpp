#include <bits/stdc++.h>
using namespace std;
#define MAXN 21

char cap[MAXN][MAXN];
map<char, char> next_c{
    {'v', 'i'},
    {'i', 'k'},
    {'k', 'a'},
    {'a', '^'}
};

void solve(){
    int n, m;
    cin>>n>>m;
    for(size_t i = 1;i<=n;++i){
        for(size_t j = 1; j<=m;++j){
            cin>>cap[i][j];
        }
    }
    char now_check = 'v';
    for(size_t j = 1;j<=m;j++){
        for(size_t i = 1;i<=n; i++){
            if(cap[i][j]==now_check){
                now_check = next_c[now_check];
                break;
            }
        }
    }
    if(now_check == '^'){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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