#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 200'001

int n, k;
int dp[MAXN];
bool vis[MAXN];
vector<int> dependency[MAXN];
int c[MAXN];

void calc(int x){
    int dp_sum = 0;
    for(int i = 0;i<dependency[x].size();i++){
        int v = dependency[x][i];
        if(vis[v] == false){
            calc(v);
        }
        dp_sum += dp[v];
    }
    dp[x] = min(c[x], dp_sum);
    if(dependency[x].size()==0){
        dp[x] = c[x];
    }
    vis[x] = true;
}

void solve(){
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>c[i];
        dependency[i].clear();
        vis[i] = false;
    }
    int tmp = -1;
    for(int i = 1;i<=k;i++){
        cin>>tmp;
        c[tmp] = 0;
    }
    for(int i = 1;i<=n;i++){
        int m;
        cin>>m;
        for(int j = 1;j<=m;j++){
            int tmp;
            cin>>tmp;
            dependency[i].push_back(tmp);
        }
    }
    for(int i = 1;i<=n;i++){
        calc(i);
    }
    for(int i = 1;i<=n;i++){
        if(i!=1){
            cout<<" ";
        }
        cout<<dp[i];
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}