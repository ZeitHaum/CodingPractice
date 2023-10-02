#include <bits/stdc++.h>
using namespace std;
#define MAXN 30'0001
#define MOD 998244353
#define int long long
#define DEBUG
// #undef DEBUG
int n;
int a[MAXN];
//0 val, 1 cnt
int zero_sum[32][2];
int one_sum[32][2];

void swap_zo(int i){
    swap(zero_sum[i][0], one_sum[i][0]);
    swap(zero_sum[i][1], one_sum[i][1]);
}

int calc_delta(int x){
    //update zero, ones
    for(int i = 0; i<32; i++){
        (zero_sum[i][0] += zero_sum[i][1]) %= MOD;
        (one_sum[i][0] += one_sum[i][1]) %= MOD;
    }
    bitset<32> now_a (a[x]);
    for(int i = 0; i<32; i++){
        if(now_a.test(i)){
            swap_zo(i);
            one_sum[i][1]++;
            one_sum[i][0]++;
        }
        else{
            zero_sum[i][1]++;
            zero_sum[i][0]++;
        }
    }
    int ret = 0;
    for(int i = 0; i<32; i++){
        ret = (ret + ((1ll<<i) * one_sum[i][0]) % MOD) % MOD;
    }
    return ret;
}

void solve(){
    cin>>n;
    for(int i = 0; i<32; i++){
        zero_sum[i][0]  = 0;
        zero_sum[i][1]  = 0;
        one_sum[i][0]  = 0;
        one_sum[i][1]  = 0;
    }
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    int ans = 0;
    for(int i = 1; i<= n; i++){
        ans = (ans + calc_delta(i)) % MOD;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    for(int i = 1; i <= t; ++i){
        solve();
    }
}
/*
// 3
// 1 3 2
*/