#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 5e5+1;
int size_tr[MAX_SIZE];
int h[MAX_SIZE];
int top[MAX_SIZE];
int fa[MAX_SIZE];
int heavy_son[MAX_SIZE];
vector adj(MAX_SIZE,vector<int>(0));

void dfs_1(int root){
    int sz = 1;
    for(int v:adj[root]){
        if(v==fa[root]) continue;
        fa[v] = root;
        h[v] = h[root]+1;
        dfs_1(v);
        sz+= size_tr[v];
        if(heavy_son[root]==0 || size_tr[v]>size_tr[heavy_son[root]]){
            heavy_son[root] = v;
        }
        
    }
    size_tr[root] = sz;
};
void dfs_2(int root,int tp){
    for(int v:adj[root]){
        if(v==fa[root]) continue;
        if(v==heavy_son[root]){
            top[v]= tp;
            dfs_2(v,tp);
        }
        else{
            top[v] = v;
            dfs_2(v,v);
        }
    }
};
int lca(int u,int v){
    while(top[u]!=top[v]){
        if(h[top[u]]<h[top[v]]) swap(u,v);
        u = fa[top[u]];
    }
    return h[u]<h[v]?u:v;
};
int main(){
    h[0] = -1;
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,root;
    cin>>n>>m>>root;
    int u,v;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    top[root] = root;
    dfs_1(root);
    dfs_2(root,root);
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        cout<<lca(u,v)<<"\n";
    }
}