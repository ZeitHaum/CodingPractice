#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 10'0001

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n;
int a[MAXN];
int lf[MAXN];
int rf[MAXN];
int accu_l[MAXN];
int accu_r[MAXN];

void solve(){
    cin >> n;
    for(int i = 1; i<=n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i<=n; ++i){
        if(i == 1) rf[i] = 1;
        else if(i > 1 && i < n){
            lf[i] = (a[i] - a[i - 1] < a[i + 1] - a[i])? (1) : (a[i] - a[i - 1]);
            rf[i] = (a[i + 1] - a[i] < a[i] - a[i - 1]) ? (1) : (a[i + 1] - a[i]);
        }
        else if(i == n) lf[i] = 1;
    }
    for(int i = 1; i<=n; ++i){
        if(i == 1){
            accu_l[i] = 0;
        }
        else accu_l[i] = accu_l[i - 1] + lf[i];
    }
    for(int i = n; i>= 1; --i){
        if(i == n) {
            accu_r[i] = 0;
        }
        else accu_r[i] = accu_r[i + 1] + rf[i];
        // cout << accu_l[i] <<',' << accu_r[i] << "\n";
    }
    int m;
    cin >> m;
    for(int i = 1; i<=m; ++i){
        int x, y;
        cin >> x >> y;
        if(x > y){
            if(y == 1){
                cout << accu_l[x] << '\n';
            } 
            else{
                cout << accu_l[x] - accu_l[y] << '\n';
            }
        }
        else{
            if(y == n){
                cout << accu_r[x] << '\n';
            }
            else{
                cout << accu_r[x] - accu_r[y] << "\n";
            }
        }
    }
}

signed main(){
    fast_io();
    int t;
    cin >> t;
    for(int i = 0; i<t; ++i){
        solve();
    }
}