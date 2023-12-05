#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MOD 998244353

struct dp_Info{
    int txt; // 包含 txt 的所有种类
    int no_txt;// 不包含 txt 的所有种类
    int no_txt_tx;// 不包含 txt 的所有种类且最后结尾是tx
};

vector<dp_Info> dp(20'0001);

inline void init(){
    dp[0].txt = 0;
    dp[0].no_txt = 0;
    dp[0].no_txt_tx = 0;
    dp[1].txt = 0;
    dp[1].no_txt = 26;
    dp[1].no_txt_tx = 0;
    dp[2].txt = 0;
    dp[2].no_txt = 26 * 26;
    dp[2].no_txt_tx = 1;
    dp[3].txt = 1;
    dp[3].no_txt = 26*26*26 - 1;
    dp[3].no_txt_tx = 26;
    int p26 = 26 * 26 * 26;
    for(int i = 4; i<= 20'0001; ++i){
        p26 = (26 * p26) % MOD;
        dp[i].txt = (26 * dp[i - 1].txt + (MOD + dp[i - 3].no_txt -  dp[i - 3].no_txt_tx)) % MOD;
        dp[i].no_txt = (MOD + p26 - dp[i].txt) % MOD;
        dp[i].no_txt_tx = (MOD + dp[i-2].no_txt - dp[i-2].no_txt_tx) % MOD;
    }    
}

void solve(){
    int n;
    cin >> n;
    if(n < 3) cout << 0 << '\n';
    else if(n == 3) cout << 1 << "\n";
    else{
        cout << dp[n].txt << '\n';
    }
}

signed main(){
    init();
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i){
        solve();
    }
}