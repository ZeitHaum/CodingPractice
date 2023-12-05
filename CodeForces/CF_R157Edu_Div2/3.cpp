#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXC 51
#define MAXL 6
#define MAXN 20'0001
int cnt[MAXC][MAXL];
string S[MAXN];
int ss[MAXN];

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve(){
    int n;
    cin>>n;
    for(int i = 0; i< MAXC; ++i){
        for(int j = 1 ; j < MAXL; ++j){
            cnt[i][j] = 0;
        }
    }
    for(int i = 1; i<= n; ++i){
        cin>>S[i];
        int sum = 0;
        for(int j = 0; j< S[i].size(); j++){
            sum += S[i][j] - '0';
        }
        cnt[sum][S[i].size()] ++;
        ss[i] = sum;
    }
    int ans = 0;
    for(int i = 1; i<=n; ++i){
        int now_sum = 0;
        for(int j = 1; j<= S[i].size(); ++j){
            now_sum += S[i][j - 1] - '0';
            // 前
            int k = 2 * j - S[i].size();
            if(k > 0 && ss[i] - now_sum <= now_sum) ans += cnt[2 * now_sum - ss[i]][k];
            // 后
            int b = S[i].size() - j;
            int bk = 2 * b - S[i].size();
            if(bk > 0 && ss[i] - now_sum >= now_sum ) ans += cnt[ss[i] - 2 * now_sum][bk];
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    fast_io();
    int t;
    t = 1;
    for(int i = 1; i<=t; ++i){
        solve();
    }
}