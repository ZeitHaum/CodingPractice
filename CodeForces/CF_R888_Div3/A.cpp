#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k,H;
    cin>>n>>m>>k>>H;
    int ans = 0;
    for(int i = 0;i<n;i++){
        int tmp = 0;
        cin>>tmp;
        int delta = abs(tmp - H);
        // cout<<delta<<',';
        if(delta%k==0 && delta / k > 0 && delta / k < m){
            // cout<<delta<<"[]"<< ans<<' ';
            ans++;
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}