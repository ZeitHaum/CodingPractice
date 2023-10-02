#include <bits/stdc++.h>
using namespace std;
#define MAXN 10'0001
int n;
char s[MAXN];
bitset<MAXN> ans_mask;
int find_min1(){
    int ret = 0;
    for(size_t i = 1; i<=n + 1 - i; ++i){
        if(s[i] != s[n+1 - i]) ret ++;
    }
    return ret;
}
void solve(){
    cin>>n;
    ans_mask.set(0, false);
    for(size_t i = 1; i<=n; ++i) {
        cin>>s[i];
        ans_mask.set(i, false);
    }
    int min_1 = find_min1();
    for(size_t i = min_1; i<=n - min_1; ){
        ans_mask.set(i, true);
        if(n & 1) ++i;
        else i+=2;
    }
    for(size_t i = 0; i<=n; ++i){
        if(ans_mask.test(i)) cout<<'1';
        else cout<<'0';
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