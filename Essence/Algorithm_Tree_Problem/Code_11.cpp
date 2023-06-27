#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 5e5+1;
int fa[MAX_SIZE][21];
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
            if(v==fa[root][0]) continue;
            fa[v][0] = root;
            h[v] = depth+1;
            self(self,v,depth+1);
        }
    };
    dfs(dfs,root,0);
    h[0] = -1;
    for(int i = 1;i<21;i++){
        for(int j = 1;j<=n;j++){
            fa[j][i] = fa[fa[j][i-1]][i-1];
        }
    }
    auto lca = [&](int u,int v){
        if(h[u]<h[v]) swap(u,v);
        if(h[u]!=h[v]){
            for(int i = 20;i>=0;i--){
                if(h[fa[u][i]]>=h[v]) u = fa[u][i];
            }
        }
        if(u==v) return u;
        else{
            for(int i = 20;i>=0;i--){
                if(fa[u][i] != fa[v][i]){
                    u = fa[u][i];
                    v = fa[v][i];
                }
            }
            return fa[u][0];
        }
    };
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
}