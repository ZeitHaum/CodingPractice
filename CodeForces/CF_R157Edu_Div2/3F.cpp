#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXC 51
map<int, int> odd_cnt;
map<int, int> even_cnt;
inline void add(map<int, int>& m_, int x_){
    if(m_.find(x_) == m_.end()) m_[x_] = 1;
    else m_[x_] ++;
}

inline int get(map<int, int>& m_, int x_){
    if(m_.find(x_) == m_.end()) return 0;
    else return m_[x_];
}

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

inline void solve_odd(int & ans){
    
}

inline void solve_even(int& ans){
    for(auto& it : even_cnt){
        ans += it.second * it.second;
    }
}

void solve(){
    int n;
    cin >> n; 
    string s;
    for(int i = 1; i<= n; ++i){
        cin>>s;
        int ls = 0;
        int rs = 0;
        for(int j = 0; j<s.size()/ 2; ++j){
            ls += s[j] - '0';
        }
        for(int k = s.size()/ 2; k < s.size(); ++k){
            rs += s[k] - '0';
        }
        if(s.size() & 1) add(odd_cnt, rs - ls);
        else add(even_cnt, rs - ls);
    }
    int ans = 0;
    solve_odd(ans);
    solve_even(ans);
    cout<<ans<<'\n';
}

signed main(){
    fast_io();
    int t = 1;
    for(int i = 1; i<=t; ++i){
        solve();
    }
}