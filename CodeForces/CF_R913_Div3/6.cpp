#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int n;
// #define DEBUG
#ifndef DEBUG
int a[10'0001];
int b[10'0001];
#endif
#ifdef DEBUG
int a[21];
int b[21];
#endif
inline int m_add(int x, int y){
    return (x + y) % n;
}
inline int m_sub(int x, int y){
    return (x - y + n) %n;
}
bool check(int begin, bool increase){
    if(increase){
        for(int i = 0; i<n - 1; ++i){
            if(a[m_add(begin, i)] > a[m_add(begin, i + 1)]) return false;
        }
    }
    else {
        for(int i = 0; i<n - 1; ++i){
            if(a[m_sub(begin, i)] > a[m_sub(begin, i + 1)]) return false;
        }
    }
    return true;
}

inline int get_cnt(int x, int y){
    return (y - x + n) % n;
}

#define INF (1E9)
void solve(){
    cin >> n;
    for(int i = 0; i<n; ++i){
        cin >> a[i];
    }
    int p = (int)(min_element(a, a + n) - a);
    int ans = INF;
    // g_0
    bool all_same = true;
    int pos_off = 0, neg_off = 0;
    for(int i = 1;i<n;++i){
        if(a[m_add(p, i)]!=a[p]) {
            pos_off = i - 1;
            all_same = false;
            break;
        }
    }
    for(int i = 1; i<n; ++i){
        if(a[m_sub(p, i)] !=a[p]){
            neg_off = i - 1;
            all_same = false;
            break;  
        }
    }
    if(all_same) {
        cout << 0 << "\n";
        return;
    }
    int r = m_add(p , pos_off), l = m_sub(p, neg_off);
    if(check(l, true)) ans = min({ans, get_cnt(l, 0), n - get_cnt(l,0) + 2});
    if(check(r, false)) ans = min({ans, get_cnt(r, n-1) + 1, n - get_cnt(r, n-1) + 1});
    if(ans == INF) cout << "-1\n";
    else cout << ans << "\n";
}

signed main(){
    #ifndef DEBUG
    fast_io();
    #endif
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        solve();
    }
}
/*
1
5
4 1 3 4 4
*/