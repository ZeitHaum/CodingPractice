#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1'0000'0000'7

struct EqClass
{
    int l_;
    int r_;
    int x_;
    int lgx_;
    EqClass(int l, int r, int x, int lgx)
    :l_(l), r_(r), x_(x), lgx_(lgx){}
    int cal_sum(){
        return (((r_ - l_ + 1) % MOD) * lgx_) % MOD;
    }
};

// log_d(x)
int log(int d, int x){
    int now = 1;
    int ans = 0;
    while(x >= d){
        x = x / d;
        ans ++;
    }
    return ans; 
}
int pow(int p, int x){// p^x
    int ans = 1;
    while(x != 0){
        --x;
        ans *= p;
    }
    return ans;
}
int F(int d, int x){
    return pow(d, log(d, x));
}

int flow_min(int a, int c, int b){// min(a*c - 1, b);
    if(b / c >= a) return a * c - 1;
    else return b - 1;
}

struct EqManager
{
    vector<EqClass> eqcs;
    int l_;
    int r_;
    int x_;
    EqManager(int l, int r, int x)
    :l_(l), r_(r), x_(x){}
    void build(){
        int now = F(x_, l_);
        int now_lgx = log(x_, l_);
        while(now <= r_){
            eqcs.push_back({max(now, l_), flow_min(now, x_, r_ + 1), x_, now_lgx});
            //特判1E18
            if((long long)1e18 / now < x_){
                //要越界了
                break;
            }
            now *= x_;
            now_lgx ++;
        }
    }
};



void solve(){
    int l, r;
    cin>>l >> r;
    EqManager eqm2(l, r, 2);
    eqm2.build();
    int ans = 0;
    for(auto& eq: eqm2.eqcs){
        EqManager tmp(eq.l_, eq.r_, eq.lgx_);
        tmp.build();
        for(auto& seq: tmp.eqcs){
            ans = (ans + seq.cal_sum()) % MOD;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i = 1; i<=t; ++i){
        solve();
    }
}
/*
1
179 1000000000000000000
*/