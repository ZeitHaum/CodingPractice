#include <bits/stdc++.h>
using namespace std;

#define MAXN (200 * 1000 + 1)
// #define MAXN 20

std::map<int,int> pos;

struct condition{
    int u;
    int v;
    int d;
};

condition C[MAXN];

vector<vector<pair<int,int>>> adj(MAXN);
int vis[MAXN];

void solve(){
    int n, m;
    cin>>n>>m;
    pos.clear();
    std::set<int> undo_lis;
    for(int i = 1;i<=n;i++){
        adj[i].clear();
        vis[i] = 0;
        undo_lis.insert(i);
    }
    for(int i = 0;i<m;i++){
        cin>>C[i].u>>C[i].v>>C[i].d;
        adj[C[i].u].push_back(make_pair(C[i].v, C[i].d));// u在v的前面
        adj[C[i].v].push_back(make_pair(C[i].u, -C[i].d));
    }
    while(!undo_lis.empty()){
        std::queue<int>q;
        q.push(*undo_lis.begin());
        undo_lis.erase(undo_lis.begin());
        vis[q.front()] = 1;
        pos[q.front()] = 0;
        while(!q.empty()){
            int qf = q.front();
            q.pop();
            for(int i = 0;i<adj[qf].size();i++){
                int v = adj[qf][i].first;
                if(vis[v] == 0){
                    vis[v] = 1;
                    undo_lis.erase(undo_lis.find(v));
                    pos[v] = pos[qf] + adj[qf][i].second;// v在qf的后面(qf, v)
                    q.push(v);
                }
            }
        }
    }
    auto check = [&](){
        for(int i = 0;i<m;i++){
            if(pos[C[i].v] - pos[C[i].u] != C[i].d){
                return false;
            }
        }
        return true;
    };
    if(check()){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}