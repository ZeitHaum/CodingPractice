#include <bits/stdc++.h>
using namespace std;

int n;
void solve(){
    cin>>n;
    int tmp;
    for(size_t i = 1; i<=n; ++i) cin>>tmp;
    if(!(n&1)) cout<<2<<"\n"<<"1 "<<n<<"\n1 "<<n<<"\n";
    else{
        cout<<4<<"\n"<<"1 "<<n - 1<<"\n1 "<<n - 1<<"\n";
        cout<<n- 1<<" "<<n<<"\n"<<n - 1<<" "<<n<<"\n";
    }    
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