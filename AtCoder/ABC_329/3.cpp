#include <bits/stdc++.h>
using namespace std;
// #define DEBUG

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

#define MAXN 20'0001
char s[MAXN];
int max_len[26];

signed main(){
    #ifndef DEBUG
    fast_io();
    #endif
    memset(max_len, 0, sizeof(max_len));
    int n;
    cin >> n;
    for(int i =1; i<=n; ++i){
        cin >> s[i];
    }
    int last_ind = 1;
    for(int i = 2; i<=n + 1; ++i){
        if(i == n + 1 || s[i] != s[i - 1]){
            max_len[s[i - 1] - 'a'] = max(max_len[s[i - 1] - 'a'], i - last_ind);
            last_ind = i;
        }
    }
    int ans = 0;
    for(int i = 0; i< 26; ++i){
        ans += max_len[i];
        #ifdef DEBUG
        cout << char(i + 'a') << ", " << max_len[i] << '\n';
        #endif
    }
    cout << ans << "\n";
}