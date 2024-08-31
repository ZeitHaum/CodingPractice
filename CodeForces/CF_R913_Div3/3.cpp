#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

char s[20'0001];
int buk[26];

void solve(){
    int n;
    cin >> n;
    memset(buk, 0, sizeof(buk));
    for(int i = 1; i<= n; ++i){
        cin >> s[i];
        buk[s[i] - 'a']++;
    }
    auto p = max_element(buk, buk + 26);
    cout << max(n % 2 , 2*(*p) - n) << "\n";
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