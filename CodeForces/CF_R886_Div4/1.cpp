#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c;
    cin>>a>>b>>c;
    int ans[3] = {a+b, a+c, b+c};
    for(int i = 0;i<3;i++){
        if(ans[i] >= 10){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}