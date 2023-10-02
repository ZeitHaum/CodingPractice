#include <bits/stdc++.h>
using namespace std;
#define MAXN 10'0001
#define out(x) cout<<x<<'\n';cout.flush()
int n;
int da[MAXN];
int mex_now;
int mex_ptr;// the first pos leq mex_now

void move_mex(){
    if(mex_now > da[n]) return;
    for(size_t i = mex_ptr + 1; i <= n; ++i){
        if(da[i] == mex_now) ++mex_now, mex_ptr = i;
        else break;
    }
}

void solve(){
    cin>>n;
    for(size_t i = 1; i<= n; ++i){
        cin>>da[i];
    }
    sort(da + 1, da + n + 1);
    mex_now = 1;
    mex_ptr = 0;
    move_mex();
    int sb;
    out(mex_now);
    ++mex_now;
    move_mex();
    while(true){
        cin>>sb;
        if(sb == -1){out(0);}
        else if(sb<= mex_now) {out(sb);}
        else {out(mex_now);++mex_now; move_mex();}
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