#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n, k;
    cin>>n>>k;
    int a, b;
    int ans = k;
    for(int i = 1; i<=n; i++){
        cin>>a>>b;
        ans = max(min(ans - b, ans / a), 0);
    }
    cout<<ans<<'\n';
}