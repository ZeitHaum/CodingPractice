#include <bits/stdc++.h>
using namespace std;
#define MAXN 51

vector<int> a(MAXN);
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1, a.begin()+n+1);
    int ans = 0;
    for(int i = 1;i<=n/2;i++){
        ans -= a[i];
    }
    for(int i = n/2+1; i<=n;i++){
        ans += a[i];
    }
    if(n%2==1){
        ans -= a[n/2 + 1];
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}