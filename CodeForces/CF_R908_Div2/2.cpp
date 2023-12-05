#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

#define MAXN 101
#define MAXV 101
int da[MAXN];
vector<int> bk[MAXV];
int ans[MAXN];

inline void solve(){
    int n;
    cin>>n;
    for(int i = 1; i<= 100; ++i){
        bk[i].clear();
    }
    for(int i = 1; i<= n; ++i){
        cin>>da[i];
        bk[da[i]].push_back(i);
    }
    for(int i = 1; i<=n; ++i){
        ans[i] = -1;
    }
    int sec_cnt = 0;
    int thr_cnt = 0;
    for(int i = 1; i<=100; i++){
        if(bk[i].size() >= 3){
            for(int j = 0; j<bk[i].size(); ++j){
                if(j == 0 && thr_cnt & 1) ans[bk[i][j]] = 1;
                else if(j ==0 && !(thr_cnt & 1)) ans[bk[i][j]] = 3;
                else ans[bk[i][j]] = 2;
            }
            thr_cnt ++;
        }
        else{
            if(bk[i].size() == 2) {
                ans[bk[i][0]] = (sec_cnt == 0)?1 : 3;
                ans[bk[i][1]] = 2;
                sec_cnt ++;
            }
            else if(bk[i].size() == 1) ans[bk[i][0]] = 1;
        }
    }
    if(sec_cnt + thr_cnt < 2) cout<<"-1\n";
    else{
        for(int i = 1; i<= n; ++i){
            if(i != 1) cout << " "; 
            cout << ans[i];
        }
        cout << '\n';
    }
}

signed main(){
    fast_io();
    int t;
    cin>>t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}