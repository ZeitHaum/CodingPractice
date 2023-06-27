#include<bits/stdc++.h>
using namespace std;
#define MAX_N (2e5+1)
#define INF (1e9+1)
#define int long long

int n;
vector<int> req(MAX_N);
vector<int> pre_process(MAX_N);

int ceil(int n,const int& div){//\ceil{n/div}
    return (n+div-1)/div;
}

int f(int l,int r){//[l,r]
    return ceil(req[r]-req[l],2);
}

int multi_max(vector<int>comp){
    int ans = -INF;
    for(auto i: comp){
        ans = max(ans,i);
    }
    return ans;
}

int F(int l,int r){//find the maxmium, [1, l], [l+1,r], [r+1,n]
    if(l>=r || r == n) return INF;
    else{
        return multi_max({f(1,l),f(l+1,r),f(r+1,n)});
    }
}

int binary_find(const int& begin){
    if(n-(begin+1)+1 == 1) return -1;
    int r = lower_bound(req.begin()+begin+1,req.begin()+n+1,ceil(req[n]+req[begin+1],2)) - req.begin();
    return max(begin+1,r-1);// to prevent the same situation.
}

void solve(){
    cin>>n;
    int tmp = 0;
    int nex_ptr = 1;
    for(int i = 1;i<=n;i++){
        cin>>req[i];
    }
    if(n<=3){
        cout<<"0\n";
        return;
    }
    sort(req.begin()+1,req.begin()+n+1);
    req[0] = -INF;
    req[n+1] = INF;
    int ans = INF;
    for(int l = 1;l<=n-2;l++){
        ans = min(ans,F(l,binary_find(l)));
    }
    cout<<ans<<"\n";
}

signed main(){
    //fastio. IO's constant is very large(5+).
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}
/*
1
6
1 1 1 1 1 1
 */