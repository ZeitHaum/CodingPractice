#include <bits/stdc++.h>
using namespace std;
#define MAXN 51
int K[MAXN];
bitset<64> S[MAXN];
set<int> all_S;

void solve(){
    int n;
    cin>>n;
    all_S.clear();
    for(int i = 1; i<=n; i++){
        cin>>K[i];
        for(int j = 0; j< 64; j++){
            S[i].set(j, false);
        }
        int tmp;
        for(int j = 1; j <= K[i]; j++){
            cin>>tmp;
            S[i].set(tmp, true);
            all_S.insert(tmp);
        }
    }
    int ans = 0;
    for(auto& i : all_S){
        bitset<64> vis(0);
        for(int j = 1; j<=n;j++){
            if(!S[j].test(i)) vis |= S[j];
        }
        ans = max(ans, (int)vis.count());
    }   
    cout<<ans<<'\n';
}

signed main(){
    int t;
    cin>>t;
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    for(int i = 1; i<=t; i++){
        solve();
    }
}