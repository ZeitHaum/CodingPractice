#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MAXN 20'0001
int n;
int da[MAXN];
int y;

inline void calc_y(int delta){
    y = 0;
    while(delta != 0){
        delta /= 2;
        ++y;
    }
}

inline void out(int sum, int y){
    cout << sum ;
    for(int i = 1; i <= y -1; ++i){
        cout << " " << 0 ;
    }
    cout << '\n';
}

inline int ceil(int x, int d){
    return (x + d - 1) / d;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> da[i];
    }
    int min_e = *min_element(da+1, da+n+1);
    int delta = *max_element(da+1, da+n+1) - min_e;
    calc_y(delta);
    cout << y << "\n";
    int div_ = 1 << y;
    if(y <= n && y > 0){
        out(ceil(min_e, div_) * div_ - min_e , y);
    }
}

signed main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        solve();
    }
}