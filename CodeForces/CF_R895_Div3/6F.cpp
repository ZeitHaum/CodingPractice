#include <bits/stdc++.h>
using namespace std;
#define MAXN 20'0001

int adj[MAXN];// 出边, -1 表示无出边
set<int> inv_adj[MAXN]; //入边
multimap<int,int> del_weight;
map<int, int> del_hash;
int n;
int c[MAXN];
int cal_del(int v){
    int ret = 0;
    for(auto iter = inv_adj[v].begin(); iter!= inv_adj[v].end(); ++iter){
        ret -= c[*iter];
    }
    return ret + c[v];
}

void change(int v, int i){
    int to_del_weight = del_hash[v];
    del_hash[v] = i;
    //LOSE
}


void solve(){
    cin>>n;
    for(size_t i = 1; i<= n; ++i){
        cin>>adj[i];
        inv_adj[adj[i]].insert(i);
    }    
    for(size_t i = 1; i<= n; ++i){
        cin>>c[i];
    }
    //cal delta
    for(size_t i = 1; i<= n; ++i){
        del_weight.insert({cal_del(i), i});
        del_hash.insert({i, cal_del(i)});
    }
    int ans = 0;
    //Remove
    while(!del_weight.empty()){
        //Find todel
        auto to_del_it = prev(del_weight.end());
        int to_del_node = to_del_it->first;
        //Del in graph
        inv_adj[adj[to_del_node]].erase(to_del_node);
        adj[to_del_node] = -1;
        del_weight.erase(to_del_it);
        for(auto iter = inv_adj[to_del_node].begin(); iter!= inv_adj[to_del_node].end(); ++iter){
            adj[*iter] = -1;
        }
        for(auto iter = inv_adj[to_del_node].begin(); iter!= inv_adj[to_del_node].end(); ++iter){
            change(*iter, 1);
        }
        del_hash.erase(to_del_node);
        inv_adj[to_del_node].clear();
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