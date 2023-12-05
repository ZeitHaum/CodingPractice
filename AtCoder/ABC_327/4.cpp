#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 20'0001
int daa[MAXN];
int dab[MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];
int val[MAXN];

bool ans = true;

inline void connect(int x, int y){
    if(x == y){
        ans = false;
        return;
    }
    adj[x].push_back(y);
    adj[y].push_back(x);
}

inline void bfs(int x){
    queue<int> q;
    q.push(x);
    assert(val[x] == -1);
    val[x] = 0;
    vis[x] = true;
    while(!q.empty()){
        int qf = q.front();
        q.pop();
        for(int & v: adj[qf]){
            if(!vis[v]){
                assert(val[v] == -1);
                val[v] = val[qf] ^ 1;
                q.push(v);
                vis[v] = true;
            }
            else{
                if(val[v] == val[qf]) {
                    ans = false;
                    return;
                }
            }
        }
    }
}

signed main(){
    int N, M;
    cin>>N >> M;
    for(int i = 1; i<=M; i++) cin >> daa[i];
    for(int i = 1; i<=M; i++) cin >> dab[i];
    for(int i = 1; i<=M; i++) connect(daa[i], dab[i]);
    if(!ans) {
        cout<<"No\n";
        return 0;
    }
    for(int i = 1; i<=N; i++) vis[i] = false, val[i] = -1;
    for(int i = 1; i<=N; i++){
        if(!ans) {
            cout<<"No\n";
            return 0;
        }
        if(vis[i] == false) bfs(i);
    }
    if(ans)cout << "Yes\n";
    else cout << "No\n";
}