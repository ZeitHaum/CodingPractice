#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
#define MAXN 20'0001
int da[MAXN];
int db[MAXN];
vector<int> ans;
vector<int> maxlen;
int n, m; 
inline void solve(){
    ans.clear();
    maxlen.clear();
    maxlen.push_back(-1);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> da[i];
    }
    for(int i = 1; i <= m; ++i){
        cin >> db[i];
    }
    sort(db + 1, db + m + 1, greater<int>());
    // nlog n LIS
    for(int i = 1; i <= n; ++i){
        auto it = lower_bound(ans.begin(), ans.end(), da[i]);
        if(it == ans.end()) ans.push_back(da[i]);
        else *it = da[i];
        maxlen.push_back(it - ans.begin());
    }
    for(int i = n, j = ans.size(); j > 1; --i){
        if(maxlen[i] == j){
            ans[--j] = da[i];
        }
    }
    int db_pos = m + 1;
    int out_cnt = 0;
    for(int i = 1; i<= m; ++i){
        if(db[i] < ans[0]){
            db_pos = i;
            break;
        } 
        if(out_cnt != 0) cout << " ";
        out_cnt ++;   
        cout<<db[i];
    }
    for(int i = 1; i<=n; ++i){
        if(out_cnt !=0) cout << " ";
        cout <<da[i];
    }
    for(int i = db_pos; i <=m; ++i){
        if(out_cnt !=0) cout << " ";
        cout << db[i];
    }
    cout<<"\n";
}

signed main(){
    // fast_io();
    int t;
    cin>>t;
    ans.reserve(MAXN);
    maxlen.reserve(MAXN);
    for(int i = 1; i<=t; i++){
        solve();
    }
}