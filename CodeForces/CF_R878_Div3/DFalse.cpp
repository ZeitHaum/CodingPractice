#include<bits/stdc++.h>
using namespace std;
#define MAX_N (2e5+1)
#define INF (1e9+1)
#define int long long

int n;
vector<int> req(MAX_N);
map<int,bool> exist;//distinct

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
    int l = begin;
    int r = n;
    auto check = [&](int mid){
        if(F(begin,mid-1)>F(begin,mid)){
            return 1;
        }
        else{
            return 2;
        }
    };
    while(r-l>1){
        int mid = (l+r)>>1;
        if(check(mid)==1){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return l;
}

void solve(){
    cin>>n;
    int tmp = 0;
    int nex_ptr = 1;
    exist.clear();
    for(int i = 1;i<=n;i++){
        cin>>tmp;
        if(exist.count(tmp)==0){
            req[nex_ptr] = tmp;
            nex_ptr++;
            exist[tmp] = true;
        }
    }
    n = nex_ptr - 1;
    if(n<=3){
        cout<<"0\n";
        return;
    }
    sort(req.begin()+1,req.begin()+n+1);
    int ans = INF;
    req[0] = -INF;
    req[n+1] = INF;
    for(int l = 1;l<=n-2;l++){
        int r = binary_find(l);
        ans = min(ans,F(l,r));
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
9
14 19 37 59 1 4 4 98 73
 */