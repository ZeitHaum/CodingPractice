#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXV 0xffff'ffff
#define pr pair<int,int>
#define MAXN 20'0001
int n, k, a, b;
pr cities[MAXN];

int calc_dis(int i, int j){
    return abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
}

void solve(){
    int mina = MAXV, minb = MAXV;
    cin>>n >> k >> a >> b;
    for(size_t i = 1; i<=n; ++i){
        cin>>cities[i].first >> cities[i].second;
    }
    for(size_t i = 1; i<=n; ++i){
        if(i<=k) {
            mina = min(calc_dis(i, a), mina);
            minb = min(calc_dis(i, b), minb);
        }
    }
    cout<<min(mina + minb, calc_dis(a, b)) << '\n';
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