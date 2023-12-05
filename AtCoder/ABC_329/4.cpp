#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
#define MAXN 20'0001
int a[MAXN];
int f_c[MAXN];

struct candidate
{
    int no_;
    int cnt_;
    candidate(): no_(0), cnt_(0) {}
    candidate(int no, int cnt): no_(no), cnt_(cnt) {}
    bool operator<(const candidate& c) const {
        if(cnt_ != c.cnt_) return cnt_ < c.cnt_;
        else return no_ > c.no_;
    }
    bool operator>(const candidate& c) const {
        if(cnt_ != c.cnt_) return cnt_ > c.cnt_;
        else return no_ < c.no_;
    }
    bool operator==(const candidate& c) const{
        return cnt_ == c.cnt_ && no_ == c.no_;
    }
};
set<candidate, greater<candidate>> st;
inline void add(int x){
    st.erase(st.find({x, f_c[x]}));
    ++f_c[x];
    st.insert({x, f_c[x]});
}

inline int find_no(){
    return st.begin()->no_;
}


signed main(){
    #ifndef DEBUG
    fast_io();
    #endif
    int n, m;
    cin >> n >> m;
    for(int i = 1; i<=m; ++i){
        cin >> a[i];
    }
    for(int i = 1; i<=n; ++i){
        f_c[MAXN] = 0;
        st.insert({i, 0});
    }
    for(int i = 1; i<=m; ++i){
        add(a[i]);
        cout << find_no() << "\n";
    }
}