#include <bits/stdc++.h>
using namespace std;

#define MAXN (200 * 1000 + 1)
int n;
int da[MAXN];
int vis[MAXN];
int ans[MAXN];

void solve(){
    cin>> n;
    for(int i = 1;i<=n;i++){
        vis[i] = 0;
        ans[i] = 0;
    }
    for(int i = 0;i<n;i++){
        cin>>da[i];
        if(da[i]<=n){
            vis[da[i]]++;
        }
    }
    for(int i = n;i>=1;i--){
        for(int j = i; j<=n;j+=i){
            ans[j] += vis[i];
        }
    }
    cout<<*std::max_element(ans+1, ans+n+1)<<"\n";
}

int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}