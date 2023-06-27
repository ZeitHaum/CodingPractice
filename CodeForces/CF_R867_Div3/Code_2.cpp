#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n%2==1 && n>1){
        cout<<-1<<"\n";
    }
    else{
        vector<int> ans(n+1);
        for(int i = 1;i<=n;i++){
            ans[i] = i-1;
        }
        ans[1] = n;
        for(int i = 3;i<=n;i+=2){
            ans[i] = n-ans[i];//-1^(i)*(i-1)
        }
        for(int i  = 1;i<=n;i++){
            cout<<ans[i]<<(i!=n?" ":"\n");
        }
    }
}

signed main(){
    //fastio. IO's constant is very large(5+).
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}