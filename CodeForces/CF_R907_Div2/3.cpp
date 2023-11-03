#include <bits/stdc++.h>
using namespace std;
#define MAXN 20'0001
#define int long long
int da[MAXN];
void solve(){
    int n;
    cin>>n;
    int all_sum = 0;
    for(int i = 1; i<=n; ++i){
        cin>>da[i];
        all_sum += da[i];
    }
    sort(da + 1, da + n + 1);
    int pre_sum = 0;
    int ans = 0;
    for(int i = 1; i<=n; ++i){
        pre_sum += da[i];
        if(pre_sum >= (all_sum + 1) / 2) {
            ans += (all_sum + 1) / 2;
            if(pre_sum > (all_sum + 1) / 2) ans ++;
            ans += n - i;
            break;
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i = 1; i<=t; ++i){
        solve();
    }
}