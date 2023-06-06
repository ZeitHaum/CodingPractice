#include<bits/stdc++.h>
using namespace std;

struct DSU_size{
    map<int,int> f;
    int find(int x){return f[x]<0?x:f[x] = find(f[x]);}
    bool is_same(int x,int y) {return find(x)==find(y);}
    int size(int x) {return -f[find(x)];}
    int unite(int x,int y){
        x = find(x);
        y = find(y);
        if(x==y) return 0;
        if(size(x)>size(y)) swap(x,y);
        f[y]+= f[x];
        f[x] = y;
        return 1;
    } 
};

void solve(){
    
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