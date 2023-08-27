#include <bits/stdc++.h>
using namespace std;

#define MAXN 3001
int n;
bitset<MAXN> bs[MAXN];

struct invert{
    int now = 0;
    int next_now = now ^ 1;
    int states[MAXN][2][2];// counts(states[i][0] LEFT), counts(states[i][1] RIGHT)
    void add(int x){
        states[x][0][now]++;
        states[x][1][now]++;
    }
    //States transition
    void transfer(){
        for(size_t i = 1; i<=n;++i){
            states[i][0][next_now] = 0;
            states[i][1][next_now] = 0;
        }
        for(size_t i = 1; i<=n; ++i){
            if(i!=1) states[i-1][0][next_now] += states[i][0][now];
            else states[i][0][next_now] += states[i][0][now];
            if(i!=n) states[i+1][1][next_now] += states[i][1][now];
            else states[i][1][next_now] += states[i][1][now];
        }
        now = next_now;
        next_now = next_now ^ 1;
    }
    bool is_l_flip(int i){
        return states[i][0][now] & 1;
    }
    bool is_r_flip(int i ){
        return states[i][1][now] & 1;
    }
    void reset(){
        for(size_t i = 1; i<= n; ++i){
            states[i][0][now] = 0;
            states[i][1][now] = 0;
        }
    }
};
invert ivt;

void solve(){
    cin>>n;
    ivt.reset();
    char c;
    for(size_t i = 1;i <= n; ++i){
        for(size_t j = 1; j <= n; ++j){
            cin>>c;
            bs[i].set(j, c == '1');
        }
    }
    int ans = 0;
    for(size_t i = 1; i<= n; ++i){
        //calc bs[i]
        // cerr<<bs[i]<<", \n";
        bool now_invert = false;
        for(size_t j = 1; j<=n; ++j){
            now_invert ^= ivt.is_l_flip(j);
            if(now_invert) bs[i].flip(j);
            now_invert ^= ivt.is_r_flip(j);
        }
        // cerr<<bs[i]<<". \n";
        for(size_t j = 1; j<=n; ++j){
            if(bs[i].test(j)){
                ++ans;
                ivt.add(j);
            }
        }
        ivt.transfer();
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(size_t i = 1;i <= t; ++i){
        solve();
    }
}