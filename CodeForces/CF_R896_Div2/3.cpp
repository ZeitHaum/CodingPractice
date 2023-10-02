#include <bits/stdc++.h>
using namespace std;

int n, m;
int get_next(int i){
    return (i+1) % m;
}

int get_next_row(int i){
    if(i==m - 1) return 1;
    else return (i+1)%m;
}

void solve(){
    cin>> n >> m;
    if(m == 1){
        cout<<0<<'\n';
        for(size_t i = 1; i<=n; i++){
            cout<<"0\n";
        }
    }
    else {
        cout<<min(m, n+1)<<'\n';
        int next_row = 1;
        for(size_t i = 1; i<=n; ++i){
            int next_column = next_row;
            for(size_t j = 1; j<= m; ++j){
                if(j!=1) cout<<' ';
                cout<<next_column;
                next_column = get_next(next_column); 
            }
            cout<<'\n';
            next_row = get_next_row(next_row);
        }
    }
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