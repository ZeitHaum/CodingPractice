#include <bits/stdc++.h>
using namespace std;
#define MAXN 20'0001

int b[MAXN];
int a[2*MAXN + 2];
int a_ptr = 0;

void solve(){
    int n;
    cin>>n;
    a_ptr = 0;
    for(size_t i = 1;i<=n;++i){
        cin>>b[i];
        if(i==1){
            a[++a_ptr] = b[i];
        }
        else{
            if(b[i] >= b[i-1]) a[++a_ptr] = b[i];
            else{
                a[++a_ptr] = 1;
                a[++a_ptr] = b[i];
            }
        }
    }
    cout<<a_ptr<<'\n';
    for(size_t i = 1;i<=a_ptr;++i){
        cout<<a[i]<<" ";
    }
    cout<<'\n';
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