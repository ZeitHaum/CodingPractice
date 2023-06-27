#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 200'001
#define N_INF 0
 
int n;
int id_to_dfn[MAX_SIZE];
int dfn_to_id[MAX_SIZE];
int val[MAX_SIZE];
int dfs_order[MAX_SIZE];
int fa[MAX_SIZE];
int heavy_son[MAX_SIZE];
int size_tr[MAX_SIZE];
int top[MAX_SIZE];
int h[MAX_SIZE];
 
auto find_data(int i){
    return val[dfn_to_id[i]];
}
 
struct seg_tree
{   
    int s[MAX_SIZE<<2];
    void build(int l,int r,int p){
        if(l==r){
            s[p] = find_data(l);
            return;
        }
        int mid = l+r>>1;
        build(l,mid,p<<1);
        build(mid+1,r,p<<1 | 1);
        s[p] = max(s[p<<1], s[p<<1|1]);
    }
    int query(int l,int r,int L,int R,int p){
        if(L<=l && R>=r) return s[p];
        else if(l>R || r<L) return N_INF;
        else{
            int mid =  l+r>>1;
            return max(query(l,mid,L,R,p<<1), query(mid+1,r,L,R,p<<1 | 1));
        }
    }
    void update(int l,int r,int index,int val,int p){
        if(l==r && l==index) s[p] = val;
        else if(l>index || r<index) return;
        else{
            int mid = l+r>>1;
            update(l,mid,index,val,p<<1);
            update(mid+1,r,index,val,p<<1 | 1);
            s[p] = max(s[p<<1], s[p<<1 | 1]);
        }
    }
};
 
seg_tree st;
int query_on_heavy_chain(int u,int v){
    if(id_to_dfn[u]>id_to_dfn[v]) swap(u,v);
    return st.query(1,n,id_to_dfn[u],id_to_dfn[v],1);
}
 
int merge_query(int u,int v){
    int ans = 0;
    while(top[u] !=top[v]){
        if(h[top[u]] < h[top[v]]) swap(u,v);
        ans = max(ans,query_on_heavy_chain(u,top[u]));
        u = fa[top[u]];
    }
    ans = max(ans,query_on_heavy_chain(u,v));
    return ans;
};    
vector adj(0,vector<int>(0));
void dfs_1(int root){
    size_tr[root] = 1;
    for(int v:adj[root]){
        if(v==fa[root]) continue;
        fa[v] = root;
        h[v] = h[root]+1;
        dfs_1(v);
        size_tr[root] += size_tr[v];
        if(heavy_son[root]==0 || size_tr[heavy_son[root]]<size_tr[v]) heavy_son[root] = v;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("Code_18Test.txt","r",stdin);
    // freopen("Code_18out.txt","w",stdout);
    // clock_t begin_time = clock();
    int q;
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>val[i];
    }
    adj.resize(n+1);
    for(int i = 1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = 1;
    h[root] = 0;
    h[0] = -1;
 
    dfs_1(root);
    int dfs_or = 1;
    dfs_order[root] = 1;
    top[root] = root;
    id_to_dfn[root] = 1;
    dfn_to_id[1] = root;
    auto dfn_update = [&](int node){
        dfs_order[node] = ++dfs_or;
        id_to_dfn[node] = dfs_order[node];
        dfn_to_id[dfs_order[node]] = node;
    };
    auto dfs_2 = [&](auto self,int root)->void{
        if(heavy_son[root]!=0){
            dfn_update(heavy_son[root]);
            top[heavy_son[root]] = top[root];
            self(self,heavy_son[root]);
        }
        for(int v:adj[root]){
            if(v==fa[root] || v==heavy_son[root]) continue;
            dfn_update(v);
            top[v] = v;
            self(self,v);
        }
    };
    dfs_2(dfs_2,root);
    st.build(1,n,1);
    for(int i = 1;i<=q;i++){
        int type;
        cin>>type;
        if(type==1){
            int u;
            cin>>u>>val[u];
            st.update(1,n,id_to_dfn[u],val[u],1);
        }
        else{
            int u,v;
            cin>>u>>v;
            cout<<merge_query(u,v)<<"\n";
        }
    }
    // cerr<<(clock()-begin_time)/1000.0<<"\n";
}