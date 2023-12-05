#include <bits/stdc++.h>
#define int long long
using namespace std;

inline void usex(double& a, int x){
    a *= x / 100.0;
}

inline void usey(double& b, int y){
    b = max(b - y, 0.0);
}

inline double use_(double a, double b, int x, int y){
    double ret = 1E9;
    const double tmp_a = a, tmp_b = b;
    for(int i = 0; i<4; ++i){
        if(i & 1) usex(a, x);
        else usex(b, x);
        if(i >= 2) usey(a, y);
        else usey(b, y);
        ret = min(ret, a + b); 
        a = tmp_a, b = tmp_b;
    }
    return ret;
}

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<double> p(n + 1);
    for(int i = 1; i<= n; ++i){
        cin >> p[i];
    }
    sort(p.begin() + 1, p.end());
    cout<<fixed <<setprecision(12);
    if(n == 1) {
        cout << max(p[1] * x / 100.0 - y, 0.0) << "\n";
        return;
    }
    double ans = 0.0;
    for(int i = 1; i<=n - 2; ++i){
        ans += p[i];
    }
    ans += use_(p[n], p[n - 1], x, y);
    cout << ans << '\n';
}

signed main(){
    int T;
    cin >> T;
    for(int i = 1; i<=T; ++i){
        solve();
    }
}