#include <bits/stdc++.h>
using namespace std;
// #define DEBUG
#ifdef DEBUG
#define MAXN 21
#endif
#ifndef DEBUG
#define MAXN 10'0001
#endif
#define out(x) cout<<x<<'\n';cout.flush()
int n;
int da[MAXN];
bitset<MAXN> exists;

void solve(){
    cin>>n;
    for(size_t i = 0; i<= n; ++i){
        exists.set(i, false);
    }
    for(size_t i = 1; i<= n; ++i){
        cin>>da[i];
        if(da[i] >=0 && da[i] <=n) exists.set(da[i], true);
    }
    int now_mksure = n;
    int sb = -1;
    while(true){
        while(exists.test(now_mksure)){
            --now_mksure;
        }
        out(now_mksure);
        exists.set(now_mksure, true);
        --now_mksure;
        cin>>sb;
        if(sb == -1) {
            #ifdef DEBUG
            cerr<<exists<<";\n";
            #endif
            bool is_out = false;
            for(size_t i = 0; i<= n - 1; ++i) {
                if(!exists.test(i)){out(i);is_out = true;break;}
            }
            if(!is_out) {out(1'0000'0001);}
            break;
        }
        else exists.set(sb, false);
    } 
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