#include<bits/stdc++.h>
using namespace std;

//\floor{log2(x)}
int log2(int x){
    int ret = 0;
    x = x-1;
    while(x!=0){
        x = (x>>1);
        ret++;
    }
    return ret;
}

int pow2(int x){
    int ret = 1;
    for(int i = 0;i<x;i++){
        ret = (ret<<1);
    }
    return ret;
}

void solve(){
    int n,k;
    cin>>n>>k;
    int x = min(log2(n)+1,k);
    // cout<<x<<"\n";
    cout<< min(pow2(x)-1, n) + 1 << "\n";
}

signed main(){
    //fastio. IO's constant is very large(5+).
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}