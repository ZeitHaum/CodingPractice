#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

signed main(){
    #ifndef DEBUG
    fast_io();
    #endif
    int M, D;
    cin>> M >> D;
    int y, m , d;
    cin >> y >> m >> d;
    ++d;
    if(d == D + 1){
        d = 1;
        ++m;
    }
    if(m == M + 1){
        m = 1;
        ++y;
    }
    cout << y << " " << m << " " << d << '\n';

}