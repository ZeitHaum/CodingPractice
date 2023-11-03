#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#undef DEBUG
#ifndef DEBUG
#define MAXN 100'0001
#endif
#ifdef DEBUG
#define MAXN 21
#endif
#define int long long
#define s_get(i) s[i - 1]
string s;
int n;
int del_r[MAXN];

struct op_stack{
    stack<pair<int,int>> st;
    int rp = 0;
    void push(int x, int id){
        while(!st.empty() && st.top().first > x){
            del_r[st.top().second] = ++rp;
            st.pop();
        }
        st.push({x, id});
    }
    void clear(){
        while(!st.empty()){
            del_r[st.top().second] = ++rp;
            st.pop();
        }
    }
};

int calc_round(int x){
    int l = 0, r = n;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if(mid * (n + n - mid + 1) / 2 < x) l = mid;
        else r = mid;
    }
    return r;
}   

void solve(){
    cin>>s;
    int x;
    cin>>x;
    n = s.size();
    //calc del_r
    op_stack ost;
    for(int i = 1; i<=n; i++){
        ost.push(s_get(i), i);
    }
    ost.clear();
    int round = calc_round(x);
    int tr = round - 1;
    int id = x - (tr * (n + n - tr + 1 ) / 2);
    int now_id = 0;
    char ans;
    for(int i = 1; i<=n; i++){
        if(del_r[i] >= round) now_id ++;
        if(now_id == id) {
            ans = s_get(i);
            break;
        }
    }
    cout<<ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        solve();
    }
}
/*
1
dcba
5
*/