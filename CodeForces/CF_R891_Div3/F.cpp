#include <bits/stdc++.h>
using namespace std;
#define MAXN 20'0001
#define int long long

int da[MAXN];
int n;
map<int, int> val_map;

bool sqrt_int(size_t x, int& ans){
    size_t l = 0, r = min(x + 1, (size_t)2e9+1);
    while(r - l > 1){
        size_t mid = l + (r - l) / 2;
        if(mid * mid <= x) l = mid;
        else r = mid;
    }
    ans = (int)l;
    if(l * l == x) return true;
    else return false;
}

int find_cnt(int x){
    if(val_map.find(x)!=val_map.end()) return val_map[x];
    else return 0;
}

int solve_pair(int x, int y){
    if(x != y) return find_cnt(x) * find_cnt(y);
    else {
        int m = find_cnt(x);
        //C_m^2
        return m * (m - 1) / 2;
    }
}

void solve(){
    val_map.clear();
    cin>>n;
    for(size_t i = 1; i<=n; ++i){
        cin>>da[i];
        if(val_map.find(da[i])==val_map.end()) val_map[da[i]] = 1;
        else ++val_map[da[i]];
    }
    int q, x, y;
    cin>>q;
    for(size_t i = 1; i<=q; ++i){
        if(i!=1) cout<<' ';
        cin>>x>>y;
        //calc_a_j
        bool sqrt_ret;
        int sqrt_ans;
        if(y >= 0) sqrt_ret = sqrt_int((size_t)x * (size_t)x - (size_t)(4 * y), sqrt_ans);
        else sqrt_ret = sqrt_int((size_t)x * (size_t)x + (size_t)(-4 * y), sqrt_ans);
        if(sqrt_ret){
            if(!((sqrt_ans + x) & 1)){
                int p_aj = (x + sqrt_ans) / 2;
                int n_aj = (x - sqrt_ans) / 2;
                int ans = 0;
                ans += solve_pair(p_aj, x - p_aj);
                cout<<ans;
            }
            else cout<<"0";
        }
        else cout<<"0";
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