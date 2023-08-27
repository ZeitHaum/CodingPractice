#include <bits/stdc++.h>
using namespace std;
#define MAXN 20'0001
#define int long long
//Still Bugs Remains.
int da[MAXN];
multiset<int> st;
multiset<int> deltas;
int n;

void erase_deltas(int x){
    deltas.extract(x);
}

void remove(int i){
    //Remove a_i
    auto it = st.find(i);
    if(it == st.begin()){
        auto next_ = next(it);
        erase_deltas((*next_) - (*it));
    }
    else if(it == prev(st.end())){
        auto prev_ = prev(it);
        erase_deltas((*it) - (*prev_));
    }
    else{
        auto prev_ = prev(it);
        auto next_ = next(it);
        erase_deltas((*next_) - (*it));
        erase_deltas((*it) - (*prev_));
        deltas.insert((*next_) - (*prev_));
    }
    st.erase(it);
}

void insert(int x){
    //Insert prev to it
    auto it = st.lower_bound(x);
    if(it == st.begin()){
        deltas.insert((*it) - x);
    }
    else if(it == st.end()){
        if(!st.empty()) deltas.insert(x - (*prev(it)));
    }
    else{
        auto prev_ = prev(it);
        erase_deltas((*it) - (*prev_));
        deltas.insert((*it) - x);
        deltas.insert(x - (*prev_));
    }
    st.insert(x);
}

void change(int i, int x){
    remove(da[i]);
    insert(x);
    da[i] = x;
}

void solve(){
    st.clear();
    deltas.clear();
    cin>>n;
    for(size_t i = 1;i <= n; ++i){
        cin>>da[i];
        insert(da[i]);
    }
    int q;
    cin>>q;
    int ind, x;
    for(size_t i = 1; i<= q; ++i){
        cin>>ind>>x;
        if(i!=1) cout<<" ";
        if(n==1) {cout<<x;continue;}
        change(ind, x);
        cout<<(*prev(st.end())) + (*prev(deltas.end()));
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
/*
2
2
5 6
10
1 2
1 7
1 7
2 5
1 2
2 7
2 2
2 8
1 7
1 8
1
9
10
1 10
1 8
1 10
1 3
1 1
1 5
1 1
1 7
1 4
1 6
*/