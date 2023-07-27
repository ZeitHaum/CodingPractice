#include <bits/stdc++.h>
using namespace std;
#define MAXN 200'001
int col[MAXN];

void solve(){
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>col[i];
    }
    int begin_pos = n+1, end_pos = -1;
    int begin_cnt = 0, end_cnt = 0;
    for(int i = 1;i<=n;i++){
        if(col[i] == col[1]){
            begin_pos = i;
            begin_cnt++;
            if(begin_cnt == k){
                break;
            }
        }
    }
    for(int i = n;i>=1;i--){
        if(col[i] == col[n]){
            end_pos = i;
            end_cnt++;
            if(end_cnt == k){
                break;
            }
        }
    }
    if(col[1] != col[n] && begin_cnt == k && end_cnt == k && end_pos > begin_pos){
        cout<<"YES\n";
    }
    else if(col[1] == col[n] && begin_cnt==k){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

signed main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}