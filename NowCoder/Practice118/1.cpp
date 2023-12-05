#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int s_cnt[26];
int t_cnt[26];

void solve(){
    string s, t;
    cin>> s >> t;
    for(int i = 0; i<26;++i){
        s_cnt[i] = 0;
        t_cnt[i] = 0;
    }
    for(char c : s) s_cnt[c - 'a'] ++;
    for(char c : t) t_cnt[c - 'a'] ++;
    int ans = 1E9 + 7;
    for(int i = 0; i< 26; i++){
        if(t_cnt[i] != 0) ans = min(ans, s_cnt[i]/ (t_cnt[i]));
    }
    cout << ans << '\n';
}

signed main(){
    fast_io();
    int t;
    cin>> t;
    for(int i = 1; i<=t;++i){
        solve();
    }
}