#include <bits/stdc++.h>
using namespace std;
#define int long long

int int_sqrt(int x){
    int l = -1, r = min(x,(int)(1e9+1));
    while(r - l>1){
        int mid = l + (r - l)/2;
        auto check = [&](){
            if(mid*mid <= x){
                return 1;
            }
            else{
                return 2;
            }
        };
        if(check() == 1){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return r;
}

int find_x(int a,int b,int c){
    //binary search
    int l = 0, r = int_sqrt((-c)/a + 1);
    // cerr<<a<<","<<b<<","<<c;
    while(r - l > 1){
        int mid = l + (r - l)/2;
        auto check = [&](){
            if(a*mid*mid + b*mid + c<0){
                return 1;
            }
            else{
                return 2;
            }
        };
        if(check()==1){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return r;
}

void solve(){
    int n,c;
    cin>>n>>c;
    int sum_s = 0;
    int sum_s2 = 0;
    int s = 0;
    for(int i = 0;i<n;i++){
        cin>>s;
        sum_s += s;
        sum_s2 += s * s;
    }
    cout<<find_x(4*n, 4*sum_s, sum_s2 - c)<<"\n";
}

signed main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}