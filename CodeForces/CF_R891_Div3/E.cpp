#include <bits/stdc++.h>
using namespace std;
#define MAXN 20'0001
#define int long long
int n;
int da[MAXN + 1];
int x[MAXN + 1];
int multiplicity[MAXN + 1];
int pre_multiplicity[MAXN + 1];

void solve(){
    int tt;
    cin>>tt;
    //Order and distinct
    map<int, int> mp;
    int tmp;
    for(size_t i = 1;i <= tt; ++i){
        cin>>tmp;
        da[i] = tmp;
        if(mp.find(tmp)!= mp.end()) mp[tmp]++;
        else mp[tmp] = 1;
    }
    int x_ptr = 0;
    for(auto iter = mp.begin(); iter!= mp.end(); iter++){
        x[++x_ptr] = iter->first;
        multiplicity[x_ptr] = iter->second;
        if(x_ptr == 1) pre_multiplicity[x_ptr] = multiplicity[x_ptr];
        else pre_multiplicity[x_ptr] = pre_multiplicity[x_ptr - 1] + multiplicity[x_ptr];
    }
    n = x_ptr;
    //initially in x_1
    int ans = 0;
    for(size_t i = n;i >= 1; --i){
        ans += tt - pre_multiplicity[i - 1];
    }
    for(size_t i = 1;i <= n - 1; ++i){
        //Handle (x_i, x_{i+1})
        ans += (tt - pre_multiplicity[i]) * (x[i+1] - x[i] - 1);
    }
    map<int, int> ans_map{{x[1], ans}};
    for(size_t i = 2;i <= n;++i){
        //Solve points
        ans -= tt - pre_multiplicity[i-1];
        ans += pre_multiplicity[i-1];
        //Solve Range
        ans -= (x[i] - x[i - 1] - 1) * (tt - pre_multiplicity[i - 1]);
        ans += (x[i] - x[i - 1] - 1) * (pre_multiplicity[i - 1]);
        ans_map[x[i]] = ans;
    }
    for(size_t i = 1; i <= tt; ++i){
        if(i!=1) cout<<" ";
        cout<<ans_map[da[i]]; 
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    //initialization
    x[0] = 0;
    for(size_t i = 0;i<t;++i){
        solve();
    }
}