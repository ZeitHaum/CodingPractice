#include <bits/stdc++.h>
using namespace std;

#define MAXN 20'0001
#define MAXQ 20'0001
int da[MAXN];
int dq[MAXQ];
vector<int> valid_mod;
vector<int> suff_mod;

void solve(){
    int n, q;
    cin>>n >> q;
    valid_mod.clear();
    suff_mod.clear();
    for(int i = 1; i <= n; i ++){
        cin>>da[i];
    }
    for(int i = 1; i<= q; ++i) cin>>dq[i];
    for(int i = 1; i<= q; ++i) {
        if(valid_mod.empty()) valid_mod.push_back(dq[i]);
        else{
            if(dq[i] < valid_mod.back()) valid_mod.push_back(dq[i]);
        } 
    }
    suff_mod.resize(valid_mod.size());
    for(int i = valid_mod.size() - 1; i >= 0; --i){
        int add_ = 1 << (valid_mod[i] - 1);
        suff_mod[i] = (i == valid_mod.size() - 1)? add_ : add_ | suff_mod[i + 1];
    }
    reverse(valid_mod.begin(), valid_mod.end());
    reverse(suff_mod.begin(), suff_mod.end());
    for(int i = 1; i<= n; ++i){
        if(da[i] == 0) continue;    
        int s = __builtin_ffs(da[i]) - 1;
        int ind_ = upper_bound(valid_mod.begin(), valid_mod.end(), s) - valid_mod.begin();
        if(ind_ == 0) continue;
        da[i] |= suff_mod[ind_ - 1];
    }
    for(int i = 1; i<=n; ++i){
        if(i!=1) cout<<' ';
        cout<<da[i];
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    valid_mod.reserve(MAXQ);
    suff_mod.reserve(MAXQ);
    for(int i = 1; i<=t; ++i){
        solve();
    }
}