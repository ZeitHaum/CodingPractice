#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG
#undef DEBUG
signed main(){
    int n, a1, a2, b1, b2;
    cin>> n >> a1 >> a2 >> b1 >> b2;
    int l1 = 0, r1 = n;
    while(r1 - l1 > 1){
        int mid = (l1 + r1) >> 1; 
        if(mid * a1 + a2 * (mid - 1) * mid / 2 <n) l1 = mid;
        else r1 = mid;
    }
    int l2 = 0, r2 = n;
    while(r2 - l2 > 1){
        int mid = (l2 + r2) >> 1; 
        if(mid * b1 + b2 * (mid - 1) * mid /2 < n) l2 = mid;
        else r2 = mid;
    }
    #ifdef DEBUG
    cout<<r1 << "," << r2 <<'\n';
    #endif
    if(r1 < r2) cout<<"Plan A\n";
    else if(r1 > r2) cout<<"Plan B\n";
    else cout<<"Same\n";
}