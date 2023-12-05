#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct Data{
    int val;
    int ind;
    bool operator<(const Data& d) const {
        return val < d.val;
    }
};

struct Lnis{
    vector<Data> da;
    Lnis(){}
    Lnis(Data x){
        da.push_back(x);
    }
    bool operator<(const Lnis& l) const{
        if(da.empty()) return true;
        else if(l.da.empty()) return false;
        return da.back() < l.da.back();
    }
};

#define MAXN 20'0001
int da[MAXN];
int db[MAXN];
int n, m;
vector<Lnis> dilworth;
vector<int> db_pos[MAXN  + 1];
inline void solve(){
    dilworth.clear();
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> da[i];
        db_pos[i].clear();
    }
    for(int i = 1; i <= m; ++i){
        cin >> db[i];
    }
    db_pos[n + 1].clear();
    for(int i = 1; i<=n; ++i){
        auto it = lower_bound(dilworth.begin(), dilworth.end(), Lnis({da[i], i}));
        if(it == dilworth.end()) dilworth.push_back(Lnis({da[i], i}));
        else it -> da.push_back({da[i], i});
    }
    sort(db + 1, db + m + 1);
    int last = 1E9 + 7;
    int max_ind = -1;
    int max_b = -1;
    for(int i = 0; i<dilworth.size(); ++i){
        if(dilworth[i].da[0].val > max_b){
            max_b = dilworth[i].da[0].val;
            max_ind = i;
        }
    }
    int min_ind = m;
    int min_ind_v = -1;
    for(auto &x: dilworth[max_ind].da){
        int ind  = lower_bound(db + 1, db + m + 1, x.val) - db;
        for(int i = ind;i <= m && db[i] < last; ++i){
            db_pos[x.ind].push_back(i);
        }
        min_ind = ind;
        last = x.val;
        min_ind_v = x.ind;
    }
    for(int i = 1; i<min_ind; ++i){
        db_pos[min_ind_v + 1].push_back(i);
    }
    int out_cnt = 0;
    for(int i = 1; i<=n + 1; i++){
        for(int j = db_pos[i].size() - 1; j>=0; j--){
            if((++out_cnt) != 1) cout << " ";
            cout << db[db_pos[i][j]];
        }
        if(i == n + 1) continue;
        if((++out_cnt) !=1) cout << " ";
        cout << da[i];
    }
    cout << '\n';
}

signed main(){
    fast_io();
    int t;
    cin>>t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}