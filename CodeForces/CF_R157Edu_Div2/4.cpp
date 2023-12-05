#include <bits/stdc++.h>
using namespace std;
#define MAXV 32
#define MAXN 20'0001
int cnt[MAXV][2];
int now[MAXV][2];
bitset<32> ans(0);
int da[MAXN];
int dc[MAXN];
 
inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
 
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i<= n - 1; i++){
        bitset<32> bs(i);
        for(int j = 0; j < 32; j++){
            if(bs.test(j)) cnt[j][1] ++;
            else cnt[j][0] ++;
        }
    }
    for(int i = 1; i<=n -1 ; i++){
        cin >> da[i];
    }
    for(int i = 1; i<= n -1 ; i++){
        dc[i] = i == 1 ? da[1] : dc[i - 1 ] ^ da[i];
        bitset<32> bs(dc[i]);
        for(int j = 0; j < 32; j++){
            if(bs.test(j)) now[j][1] ++;
            else now[j][0] ++;
        }
    }
    for(int i =0; i<32; i++){
        if(now[i][0] +1 == cnt[i][0] && now[i][1] == cnt[i][1]) ans.set(i, false);
        else ans.set(i, true);
    }
    int ians = ans.to_ulong();
    cout << ians;
    for(int i = 1; i<= n - 1 ; i++){
        cout<< " " << (ians^dc[i]);
    }
    cout << "\n";
}
 
signed main(){
    fast_io();
    int t;
    t = 1;
    for(int i = 1; i<=t; ++i){
        solve();
    }
}