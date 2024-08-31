#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n;
#define MAXN 20'0001
int l[MAXN];
int r[MAXN];

struct Interv
{
    int l;
    int r;
    bool is_overlap(int lx, int rx){
        assert(l <= r);
        assert(lx <= rx);
        if(l > rx || r < lx) return false;
        else return true;
    }
};

bool check(int k){
    Interv valid = {0, 0};
    for(int i = 1; i<=n; ++i){
        valid.l -= k;
        valid.r += k; 
        if(!valid.is_overlap(l[i], r[i])) return false;
        valid.l = max(valid.l, l[i]);
        valid.r = min(valid.r, r[i]);
    }
    return true;
}

void solve(){
    cin >> n;
    for(int i = 1; i<=n; ++i) cin >> l[i], cin >> r[i];
    int lb = -1, rb = (*max_element(r + 1, r + n + 1)) + 1;
    while(rb - lb > 1){
        int mid = (lb + rb) >> 1;
        if(check(mid) == false) lb = mid;
        else rb = mid;
    }
    cout << rb << "\n";
}

signed main(){
    #ifndef DEBUG
    fast_io();
    #endif
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        solve();
    }
}
/*
1
3
3 8
10 18
6 11
*/