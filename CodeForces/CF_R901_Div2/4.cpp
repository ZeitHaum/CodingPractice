#include <bits/stdc++.h>
using namespace std;
#define MAXN 5001
int da[MAXN], dp[MAXN];
int n;
map<int, int> mex_dic;

void solve(){
    cin>>n;
    mex_dic.clear();
    for(int i = 1; i<= n; i++){
        cin>>da[i];  
        if(mex_dic.find(da[i]) == mex_dic.end()) mex_dic[da[i]] = 1;
        else mex_dic[da[i]] ++;
    }
    int mex_a;
    for(int i = 0; i<=n; i++){
        if(mex_dic.find(i) == mex_dic.end()){
            mex_a = i;
            break;
        }
    }
    dp[mex_a] = 0;
    for(int i = mex_a - 1; i>=0; i--){
        dp[i] = mex_a * (mex_dic[i] - 1) + i;
        for(int j = i + 1; j<mex_a; j++){
            dp[i] = min(dp[i], dp[j] + (mex_dic[i] - 1)*j + i);
        }
    }
    cout<<dp[0]<<'\n';
}

signed main(){
    int t;
    cin>>t;
    for(int i = 1;i<=t;i++){
        solve();
    }
}
/*
1
8 
0 1 2 0 1 2 0 3
*/