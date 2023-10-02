#include <bits/stdc++.h>
using namespace std;

int sqrt_int(int x){
    int l = 0, r = x;
    if(x <= 1) return x;
    while(r - l > 1){
        int mid = l + (r - l)/2;
        if(1ll * mid * mid <= x) l = mid;
        else r = mid; 
    }
    return l;
}

signed main(){
    long long x = 1e9;
    --x;
    cout<<fixed<<setprecision(20)<<sqrtl(x)<<'\n';
    // for(size_t i = 1; i<=(size_t)INT32_MAX; ++i){
    //     if(sqrt_int(i) != (int)sqrt(i)){
    //         cout<<i<<", "<< sqrt_int(i) << ", "<< (int)sqrt(i) <<'\n';
    //     }
    //     if(i % 10000000 == 0) cout<<i<<'\n';
    // }
}