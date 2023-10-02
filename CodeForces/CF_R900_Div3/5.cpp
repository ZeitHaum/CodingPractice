#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define MAXN 20'0001
int da[MAXN];
int cnt[MAXN][32];
int n;
bool check(int mid, int k, int l){
    bitset<32> t;
    for(int i = 0; i< 32; i++){
        if(cnt[mid][i] - cnt[l - 1][i] == (mid - l + 1)) t.set(i, true);
        else t.set(i, false);
    }
    return (int)t.to_ulong() >= k;
}
void solve(){
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>da[i];
    }
    for(int i = 1; i<= n; i++){
        bitset<32> tmp_b(da[i]);
        for(int j = 0; j<32; j++){
            cnt[i][j] = cnt[i - 1][j] + (int)tmp_b.test(j);
        }
    }
    int q, l, k;
    cin>>q;
    for(int i = 1; i<= q; i++){
        cin>>l>>k;
        int tl = l - 1, tr = n + 1;
        while(tr - tl > 1){
            int mid = tl + (tr - tl) / 2;
            if(check(mid, k, l)) tl = mid;
            else tr = mid;
        }
        if(i!=1) cout<<' ';
        if(tl<l) cout<<"-1"; 
        else cout<<tl;
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i<32; i++){
        cnt[0][i] = 0;
    }
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        solve();
    }
}