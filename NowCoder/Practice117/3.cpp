#include <bits/stdc++.h>
using namespace std;
#define int long long
void greed_fill(int & fill_all, int & l1, int& l2){
    if(l1 >= fill_all){
        l1 -= fill_all;
        fill_all = 0;
    }
    else{
        fill_all -= (l1 - l1 %2);
        l1 %= 2;
    }
    l2 -= (fill_all / 2);
}   
void solve(){
    int n, m, k; 
    cin>>n>>m>>k;
    int max_r = 0;
    int l1 = n, l2 = m;
    int fill_all = 0;
    if(k & 1) {
        max_r = min(n, (n + 2*m) / k);
        fill_all = max_r * k;
        l1 -= max_r;
        fill_all -= max_r;
        greed_fill(fill_all, l1, l2);
    }
    else {
        max_r = (n + 2*m) / k;
        fill_all = max_r * k;
        greed_fill(fill_all, l1, l2);
    }
    cout<< l1 + l2 << '\n';
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int T;
    cin>>T;
    for(int i = 1; i<= T; ++i){
        solve();
    }
}   