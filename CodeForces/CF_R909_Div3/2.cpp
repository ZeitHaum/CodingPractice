#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define DEBUG
#define INF 1E18 + 1

#define MAXN 150'001
int a[MAXN];
int pre_sum[MAXN];


inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

inline int get_intsum(int l, int r){
    if(l == 1) return pre_sum[r];
    else return pre_sum[r] - pre_sum[l - 1];
}

int n;
void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        pre_sum[i] = i == 1? a[i] : pre_sum[i - 1] + a[i];
    }
    if(n == 1) {
        cout << 0 << "\n";
        return ;
    }
    int ans = 0;
    for(int i = 1; i < n; ++i){
        if(n % i !=0) continue;
        int max_sum = 0, min_sum = INF;
        for(int j = 1; i * j <=n; ++j){
            int now_sum = get_intsum(1 + (j - 1) *i, j * i);
            max_sum = max(max_sum, now_sum);
            min_sum = min(min_sum, now_sum);
        }
        #ifdef DEBUG
        cout << max_sum << " , " << min_sum << ", " << i << "\n";
        #endif
        ans = max(ans, max_sum - min_sum);
    }
    cout << ans  << '\n';
}

signed main(){
    #ifndef DEBUG
    fast_io();
    #endif
    int t;
    cin>> t;
    for(int i = 1; i<=t; ++i){
        solve();
    }
    #ifdef DEBUG
    assert(0);
    #endif
}