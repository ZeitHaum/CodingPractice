#include <bits/stdc++.h>
using namespace std;
#define MAXN 10'0001
int n, k;
int a[MAXN + 1];// last = MEX(a)
bitset<MAXN + 1> buk_a;

int mex(){
    for(size_t i = 0; i<= n - 1; ++i){
        buk_a.set(a[i], true);
    }
    for(size_t i = 0; i <= n; ++i){
        if(!buk_a.test(i)) return i;
    }
    return -1;
}

int next_i(const int& begin, int i){
    return (begin + i) % (n + 1);
}

void solve(){
    cin>>n>>k;
    for(size_t i = 0; i <= n; ++i){
        buk_a.set(i, false);
    }
    for(size_t i = 0; i <= n - 1; ++i){
        cin>>a[i];
    }
    a[n] = mex();
    int begin = (n + 1 - (k % (n + 1))) % (n + 1);
    for(size_t i = 0; i<= n - 1; ++i){
        if(i!=0) cout<<' ';
        cout<<a[next_i(begin, i)];
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