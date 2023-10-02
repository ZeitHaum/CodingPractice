#include <bits/stdc++.h>
using namespace std;
#define MAXN 20'0001
#define MOD 998244353
#define DEBUG
#undef DEBUG
#define s_get(i) (s[i-1])
#define mult(x, y) (x * y % MOD)
int A[MAXN];
#define int long long
vector<int> C;
int n;
void solve(){
    C.clear();
    int now = 1;
    string s;
    cin>>s;
    n = s.size();
    for(int i = 1; i<=n; i++){
        if(i!=1){
            if(s_get(i - 1) == s_get(i)) now++;
            else {
                if(now > 1) C.push_back(now);
                now = 1;
            }
        }
    }
    if(now > 1) C.push_back(now);
    int ans1 = 0, ans2 = 1;
    for(int i = 0; i<C.size();i++){
        ans1 += C[i] - 1;
        ans2 = mult(ans2, C[i]); //C_{m}^{m - 1}
    }
    ans2 = mult(ans2, A[ans1]);
    cout<<ans1<<' '<<ans2<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    C.resize(MAXN);
    A[0] = 1;
    A[1] = 1;
    for(int i = 2; i<MAXN; i++){
        A[i] = mult(A[i - 1], i);
    }
    int t;
    cin>>t;
    for(int i = 1; i <= t; ++i){
        solve();
    }
}