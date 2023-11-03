#include <bits/stdc++.h>
using namespace std;
#define MAXN 21
int da[MAXN];

bool solve(){
    int n;
    cin>>n;
    for(int i = 1; i<= n; i++){
        cin>>da[i];
    }
    int now = 2;
    while(now  * 2 <= n){
        for(int i = now + 1; i + 1<=now * 2; i ++){
            if(da[i] > da[i + 1]) return false;
        }
        now *= 2;
    }
    for(int i = now + 1; i + 1 <= n; i++){
        if(da[i]  > da[i + 1]) return false;
    }
    return true;
}

signed main(){
    int t;
    cin>>t;
    for(int i = 1; i<=t; ++i){
        if(solve()){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
}