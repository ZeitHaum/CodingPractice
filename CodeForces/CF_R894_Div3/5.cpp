#include <bits/stdc++.h>
using namespace std;

#define MAXN 20'0001 
#define int long long
int n,m,d;
int a[MAXN];
priority_queue<int, vector<int>, greater<int>> pq;
int pq_sum = 0;

void add(int x){
    if(pq.size() < m){
        pq.push(x);
        pq_sum += x;
    }
    else{
        if(pq.top() < x){
            pq_sum-= pq.top();
            pq.pop();
            pq.push(x);
            pq_sum += x;
        }
    }
}

void clear(){
    while(!pq.empty()){
        pq.pop();
    }
    pq_sum = 0;
}

void solve(){
    clear();
    cin>>n>>m>>d;
    for(size_t i = 1;i<=n;++i){
        cin>>a[i];
    }
    int ans = 0;
    for(size_t r = 1;r <= n; ++r){
        if(a[r]>0){
            add(a[r]);
            ans = max(pq_sum - d * (int)r, ans);
        }
    }
    cout<<max(ans, 0ll)<<"\n";
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