#include <bits/stdc++.h>
using namespace std;
#define MAXN 20'0001

map<int, int> count_;
int a[MAXN];
int b[MAXN];
int n;

bool check(){
    b[1] = n;
    for(size_t i = 2;i<=n;++i){
        if(count_.count(i-1)!=0){
            b[i] = b[i-1] - count_[i-1];
        }
        else b[i] = b[i-1];
    }
    for(size_t i = 1;i<=n;++i){
        // cerr<<a[i]<<", "<<b[i]<<"\n";
        if(a[i]!=b[i]) return false;
    }
    return true;
}

void solve(){
    count_.clear();
    cin>>n;
    for(size_t i = 1;i<=n;++i){
        cin>>a[i];
        if(count_.count(a[i])==0){
            count_[a[i]] = 1;
        }
        else{
            ++count_[a[i]];
        }
    }
    if(check()){
        cout<<"YES\n";
    }
    else cout<<"No\n";
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