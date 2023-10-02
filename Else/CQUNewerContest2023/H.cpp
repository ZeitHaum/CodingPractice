#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 101
int da_x[MAXN];
int da_y[MAXN];
signed main(){
    int n;
    cin>>n;
    for(int i = 1; i<= n; i++){
        cin>>da_x[i];
        cin>>da_y[i];
    }
    if(n < 3) {
        cout<<"-1\n";
        return 0;
    }
    pair<int, int> k1 = {(da_y[2] - da_y[1]) , (da_x[2] - da_x[1])};
    pair<int, int> k2 = {(da_y[3] - da_y[2]) , (da_x[3] - da_x[2])};
    int g1 = __gcd(k1.first, k1.second);
    int g2 = __gcd(k2.first, k2.second);
    k1.first = k1.first / g1;
    k1.second = k1.second / g1;
    k2.first = k2.first / g2;
    k2.second = k2.second / g2;
    if(k1 == k2){
        if(k1.first == 0) cout<<"Const\n";
        else cout<<"Line\n";
    }
    else {
        cout<<"Parabola\n";
    }
}