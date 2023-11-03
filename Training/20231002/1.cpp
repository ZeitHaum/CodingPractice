#include <bits/stdc++.h>
using namespace std;
#define MAXN 20'0001
int n, k;
int da[MAXN];
int dh[MAXN];
int hl[MAXN];
int hr[MAXN];
int lrp = 0;
void solve(){
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>da[i];
    }
    for(int i = 1; i <= n; i++) cin>>dh[i];
    int now_p = 1; 
    while(now_p <= n){
        ++lrp;
        hl[lrp] = now_p;
        while(now_p + 1 <= n){
            if(dh[now_p] % dh[now_p + 1]!=0) break; 
            ++now_p;
        }
        hr[lrp] = now_p;
        ++now_p;
    }
    int ans = 0;
    for(int i = 1; i<= lrp; i++){
        int now_l = hl[i];
        int now_r = hl[i];
        int now_sum = da[now_r];
        for(; now_r<= hr[i]; ){
            while(now_sum <k){
                now_r ++;
                now_sum += da[now_r];
            }            
            now_sum -= da[now_r];
            ans = max(ans, now_r - now_l);
            now_sum -= da[now_l];
            now_l ++; 
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    int t;
    cin>>t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}