#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
#define MAXN 100'0001
int dx[MAXN];

signed main(){
    fast_io();
    int n, m , X;
    cin >> n >> m >>  X;
    for(int i = 1; i<= n; ++i){
        cin >> dx[i];
    }
    int min_y = 1E9 + 7;
    int max_y = 0;
    int tmp;
    for(int j = 1; j<= m; ++j){
        cin>> tmp;
        min_y = min(tmp, min_y);
        max_y = max(tmp, max_y);
    }
    int ans = X;
    int tmin_y, tmax_y;
    for(int i = 1; i<=n; ++i){
        tmin_y = min(min_y, ans);
        tmax_y = max(max_y, ans);
        if(dx[i] >= tmin_y && dx[i]<= tmax_y) ans = dx[i];
        else if(dx[i] > tmax_y) ans = tmax_y;
        else ans = tmin_y;
    }
    cout << ans << '\n';
}