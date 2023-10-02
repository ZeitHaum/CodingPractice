#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define DEBUG
#ifdef DEBUG
#define MAXN 21
#endif
#ifndef DEBUG
#define MAXN 20'0001
#endif
#define out_no() cout<<"NO\n";return
int n;
int a[MAXN];
int cg[MAXN][2];//[0] shoud add, [1] shoud sub
int check_delta[sizeof(int) << 3][2];
int avg_a;
bool rec_break = false;
 
void dec_dt(size_t x, int i){
    // decompress delta
    if(x == 0) cg[i][0] = 0, cg[i][1] = 0;
    else {
        int bin_cnt = (sizeof(int)<<3) - (__builtin_clzll(x));
        int zero_suf_cnt = __builtin_ctzll(x);
        // #ifdef DEBUG 
        // cerr<<"{"<<bin_cnt<<"/"<<zero_suf_cnt<<"}";
        // #endif
        if(bin_cnt - zero_suf_cnt != __builtin_popcountll(x)) {
            rec_break = true;
            out_no();
        }
        else{
            cg[i][0] = bin_cnt;// 1 << bin_cnt
            cg[i][1] = zero_suf_cnt;// 1 << zero_suf_cnt
        } 
    }    
}
 
void calc_delta(){
    for(size_t i = 1; i<= n; ++i){
        int dt = avg_a - a[i];// delta, should add
        dec_dt((size_t)(abs(dt)), i);
        if(rec_break) return;
        if(dt <0) swap(cg[i][0], cg[i][1]);   
        // #ifdef DEBUG
        // cerr<<dt<<","<<cg[i][0]<<","<<cg[i][1]<<";";
        // #endif
    }
}
 
void solve(){
    cin>>n;
    rec_break = false;
    memset(check_delta, 0, sizeof(int) << 6);
    int sum_a = 0;
    for(size_t i = 1; i<=n; ++i){
        cin>>a[i];
        sum_a += a[i];
    }
    if(sum_a % n !=0) {out_no();}
    avg_a = sum_a / n;
    calc_delta();
    if(rec_break) return;
    //check delta
    for(size_t i = 1; i<=n; ++i){
        check_delta[cg[i][0]][0] ++;
        check_delta[cg[i][1]][1] ++;
    }
    for(size_t i = 0; i< (sizeof(int) << 3); ++i){
        #ifdef DEBUG
            cerr<<check_delta[i][0]<<'-'<<check_delta[i][0]<<";";
        #endif
        if(check_delta[i][0] != check_delta[i][1]) {out_no();}
    }
    cout<<"YES\n";
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(size_t i = 0;i<t;++i){
        solve();
    }
}