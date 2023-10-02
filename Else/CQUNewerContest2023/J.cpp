#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1'000'000'007
int quick_pow(int x, int y){
    if(y == 0) return 1;
    else {
        int ans = quick_pow(x, y/2);
        ans = ans * ans % MOD;
        if(y & 1) ans = ans * x % MOD;
        return ans;
    }
    return -1;
}

signed main(){
    int t;
    cin>>t;
    for(int i = 1; i<=t;i++){
        int n,m;
        cin>>n>>m;
        cout<<quick_pow(m + 1, n)<<'\n';
    }
}