#include <bits/stdc++.h>
using namespace std;
#define MAXM 10'0001

int n, m, d;
int s[MAXM];
int delta_ans[MAXM];

int ceil(int x, int d){
    return (x + d - 1) / d;
}

int f(int l, int r){
    return ceil(r - l, d) - 1;
}

bool div_int(int x, int d){
    return x % d == 0;
}

int calc_ans(){
    int ret = 0;
    for(size_t i = 1; i<= m - 1; ++i){
        ret+= f(s[i], s[i+1]);
    }
    ret += m;
    if(s[1]!=1){
        ret += 1 + f(1, s[1]);
    }
    ret += f(s[m], n) + (int)div_int(n - s[m], d);
    return ret;
}

void solve(){
    cin>>n>>m>>d;
    for(size_t i = 1;i<=m;++i){
        cin>>s[i];
    }
    int unremoved_ans = calc_ans();
    for(size_t i = 1;i<=m;++i){
        if(i==1){
            if(s[1] == 1) delta_ans[i] = 0;
            else delta_ans[i] = -f(1, s[1]) - f(s[1], s[2]) + f(1, s[2]) -1;
        }  
        else if(i==m){
            delta_ans[i] = -(int)div_int(n - s[m], d) - f(s[m], n) - f(s[m-1], s[m]) + f(s[m-1], n) + (int)(div_int(n - s[m-1], d)) - 1;
        }
        else delta_ans[i] = -f(s[i-1], s[i]) - f(s[i], s[i+1]) + f(s[i-1], s[i+1]) - 1;
        // cerr<<"delta_ans["<<i<<"]"<<":"<< delta_ans[i]<<'\n';
    }
    sort(delta_ans+1, delta_ans+m+1);
    int count_ans = 1;
    for(size_t i = 2;i <= m; ++i){
        if(delta_ans[i]!=delta_ans[1]){
            break;
        }
        else count_ans = i;
    }
    cout<<unremoved_ans + delta_ans[1]<<" "<<count_ans<<'\n';
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