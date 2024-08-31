#include <iostream>
using namespace std;

void solve(){
    int l, r;
    cin >> l >> r;
    #define odd_cnt1(l) ((l&1)?(l/2+1):(l/2))
    cout << (odd_cnt1(r) - odd_cnt1((l - 1))) / 2 << "\n"; 
}

signed main(){
    int t;
    cin>>t;
    for(int i = 0; i <t; ++i){
        solve();
    }
}