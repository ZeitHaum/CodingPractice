#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
int a[MAXN];

void solve(){
    int n, m;
    cin >> n >> m;
    int maxA = INT32_MIN;
    for(int i = 1; i<=n; ++i){
        cin >> a[i];
        maxA = max(a[i], maxA);
    }
    char sign;
    int l, r;
    for(int i = 1; i<=m; ++i){
        cin >> sign >> l >> r;
        if(sign == '+'){
            if(maxA <= r && maxA>=l){
                maxA++;
            }
        }
        else{
            if(maxA <= r && maxA >= l){
                maxA--;
            }
        }
        cout << maxA << " ";
    }
    cout << "\n";
}

signed main(){
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(int i = 0; i <t; ++i){
        solve();
    }
}