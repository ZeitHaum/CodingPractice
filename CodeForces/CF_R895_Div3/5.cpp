#include <bits/stdc++.h>
using namespace std;
#define MAXN 10'0001
#define s_get(i) s[i-1]
int a0, a1;
string s;
int da[MAXN];
int pre_xor[MAXN];
int n;

int get_range(int l, int r){
    if(l == 1) return pre_xor[r];
    else return pre_xor[r] ^ pre_xor[l - 1];
}

void solve(){
    cin>>n;
    for(size_t i = 1; i<=n; ++i){
        cin>>da[i];
        if(i == 1) pre_xor[i] = da[i];
        else pre_xor[i] = pre_xor[i - 1] ^ da[i];
    }
    a0 = 0, a1 = 0;
    cin>>s;
    for(size_t i = 1; i<=n; ++i){
        if(s_get(i)=='0') a0^= da[i];
        else a1^= da[i];
    }
    int q;
    int op;
    int l,r;
    int out_op;
    cin>>q;
    for(size_t i = 1; i<=q; ++i){
        cin>>op;
        if(op == 1){
            cin>>l>>r;
            a0 ^= get_range(l, r);
            a1 ^= get_range(l, r);
        }
        else{
            cin>>out_op;
            if(out_op) cout<<a1;
            else cout<<a0;
            cout<<' ';
        }
    }
    cout<<'\n';
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