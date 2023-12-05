#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

#define MAXN 20'0001
int n, k;
int da[MAXN];
bool vis[MAXN];

inline int move_forward(int ind, int x){
    if(ind - x  >= 1) return ind - x;
    else {
        x -= ind;
        ind = n;
        return ind - x;
    }
}

inline bool check(){
    int now = da[n];
    int cnt = 0;
    int now_ind = n;
    int r_cnt = 0;
    while(true){
        if(vis[now_ind] == true) return true;
        if(now > n) return false;
        cnt += now;
        r_cnt ++;
        vis[now_ind] = true;
        if(r_cnt >= k) return true;
        now_ind = move_forward(now_ind, now);
        now = da[now_ind];
    }
}

inline void solve(){
    cin>>n >> k;
    for(int i = 1; i<= n; i++){
        cin>>da[i];
        vis[i] = false;
    }
    if(check()) cout << "YES\n";
    else cout <<"NO\n";
}

signed main(){
    fast_io();
    int t;
    cin>>t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}