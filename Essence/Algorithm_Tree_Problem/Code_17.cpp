#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 500001
#define P_INF 1'000'000'000

int euler_map[MAX_SIZE];
int euler_map_inv[MAX_SIZE];
int euler_path[MAX_SIZE<<1];
int map_path_ind[MAX_SIZE];
bool vis[MAX_SIZE];

struct seg_tree
{       
    int s[MAX_SIZE<<3];
    void build(int l,int r,int p){
        if(l==r){
            s[p] = euler_path[l];
            return;
        }
        int mid = l+r>>1;
        build(l,mid,p<<1);
        build(mid+1,r,p<<1|1);
        s[p] = min(s[p<<1],s[p<<1|1]);
    }

    int query(int l,int r,int L,int R,int p){
        if(L<=l && R>=r) return s[p];
        else if(l>R || r<L) return P_INF;
        else{
            int mid = l+r>>1;
            return min(query(l,mid,L,R,p<<1),query(mid+1,r,L,R,p<<1|1));
        }
    }
};

seg_tree st;

int main(){
    int n,m,root;
    cin>>n>>m>>root;
    vector adj(n+1,vector<int>(0));
    for(int i = 1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis[root] = true;
    euler_map[root] = 1;
    euler_map_inv[1] = root;
    int dfs_order = 1;
    int ep = 0;
    auto dfs_euler = [&](auto self,int root)->void{
        vis[root] = true;
        euler_path[++ep] = euler_map[root];
        map_path_ind[euler_map[root]] = ep;
        for(int v : adj[root]){
            if(vis[v]==false){
                euler_map[v] = ++dfs_order;
                euler_map_inv[dfs_order] = v;
                self(self,v);
                euler_path[++ep] = euler_map[root];
                map_path_ind[euler_map[root]] = ep;
            }
        }
    };
    dfs_euler(dfs_euler,root);
    st.build(1,2*n-1,1);
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u = map_path_ind[euler_map[u]];
        v = map_path_ind[euler_map[v]];
        if(u>v) swap(u,v);
        cout<<euler_map_inv[st.query(1,2*n-1,u,v,1)]<<endl;
    }
}