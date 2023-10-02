#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 30'0001
int n;
int a[MAXN];
int b[MAXN];
void solve(){
    cin>>n;
    int sum_a = 0, sum_b = 0;
    for(int i = 1;i<=n; ++i){
        cin>>a[i];
        sum_a += a[i];
    }
    for(int i = 1; i<=n; ++i) {
        cin>>b[i];
        sum_b += b[i];
    }    
    //row 
    int r_min = *(min_element(a+1, a+n+1));
    int c_min = *(min_element(b+1, b+n+1));
    cout<<min(c_min*n + sum_a, r_min*n + sum_b)<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i = 1; i <= t; ++i){
        solve();
    }
}