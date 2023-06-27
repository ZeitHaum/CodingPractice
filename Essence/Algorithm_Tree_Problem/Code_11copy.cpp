#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 5e5+1;
int fa[21][MAX_SIZE];
int h[MAX_SIZE];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,root;
    cin>>n>>m>>root;
    vector adj(n+1,vector<int>(0));
    int u,v;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dfs = [&](auto self,int root,int depth)->void{
        for(int v: adj[root]){
            if(v==fa[0][root]) continue;
            fa[0][v] = root;
            h[v] = depth+1;
            self(self,v,depth+1);
        }
    };
    dfs(dfs,root,0);
    h[0] = -1;
    for(int i = 1;i<21;i++){
        for(int j = 1;j<=n;j++){
            fa[i][j] = fa[i-1][fa[i-1][j]];
        }
    }
    auto lca = [&](int u,int v){
        if(h[u]<h[v]) swap(u,v);
        if(h[u]!=h[v]){
            for(int i = 20;i>=0;i--){
                if(h[fa[i][u]]>=h[v]) u = fa[i][u];
            }
        }
        if(u==v) return u;
        else{
            for(int i = 20;i>=0;i--){
                if(fa[i][u] != fa[i][v]){
                    u = fa[i][u];
                    v = fa[i][v];
                }
            }
            return fa[0][u];
        }
    };
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
}