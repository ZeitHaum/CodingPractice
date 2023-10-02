#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 10'0001
int w[MAXN];
int s[MAXN];
int sp = 0;
signed main(){
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>w[i];
    }
    for(int i = 1, s_now = 1; s_now <=n; ++i, s_now += i){
        s[++sp] = s_now;
    }
    int q;
    cin>>q;
    for(int i = 1; i<=q; i++){
        int op, x;
        cin>>op >> x;
        int v;
        if(op == 1){
            cin>>v;
            w[x] += v;  
        } 
        else{
            int ans = w[x];
            w[x] = 0;
            for(int j = 1; x + s[j] <= n; j++){
                ans += w[x + s[j]];
                w[x + s[j]] = 0;
            }
            cout<<ans << '\n';
        }
    }
}