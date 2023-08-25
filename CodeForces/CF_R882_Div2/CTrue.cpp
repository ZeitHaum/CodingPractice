#include <iostream>
using namespace std;
#define MAXV 256
#define MAXN 200'001

int S[MAXV];
int da[MAXN];

void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>da[i];
    for(int i = 0;i<MAXV;i++) S[i] = 0;
    S[da[1]] = 1;
    int now_prexor = da[1];
    int max_val = da[1];
    for(int i = 2;i<=n;i++){
        now_prexor = now_prexor ^ da[i];
        for(int j = 0;j<MAXV;j++){
            if(S[j] == 1){
                max_val = max(max_val, j^now_prexor);
            }
        }
        max_val = max(max_val, now_prexor);
        S[now_prexor] = 1;
    }
    cout<<max_val<<"\n";
}

signed main(){
    int t;cin>>t;
    for(int i = 0;i<t;i++) solve();
}