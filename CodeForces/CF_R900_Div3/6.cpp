#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG
#undef DEBUG
map<int, int> n_cnt;
map<int, int> d_cnt;
int now_d = 1;
#define ADD_(x, cnt) if(cnt.find(x) == cnt.end()){cnt[x] = 1;} else {cnt[x]++;} 
#define find_(x, cnt) (cnt.find(x) == cnt.end()? 0:cnt[x])

void assign_decomp(int x, map<int, int>& cnt){
    cnt.clear();
    while(x % 2 == 0){
        x /= 2;
        ADD_(2, cnt);
    }
    int maxi = sqrt(x) + 1;
    for(int i = 3; i<= maxi; i+=2){
        while(x % i ==0){
            x /= i;
            ADD_(i, cnt);
        }
    }
    if(x > 2) ADD_(x, cnt);
}

void add_decomp(int x){
    now_d /= (find_(2, n_cnt) + 1);
    while(x % 2 == 0){
        x = x / 2;
        ADD_(2, n_cnt)
    }
    now_d *= (find_(2, n_cnt)+1);
    int maxi = sqrt(x) + 1;
    for(int i =  3; i<= maxi; i+=2){
        now_d /= (find_(i, n_cnt) + 1);
        while(x % i == 0){
            x /= i;
            ADD_(i, n_cnt)
        }
        now_d *= (find_(i, n_cnt) + 1);
    } 
    if(x > 2) {
        now_d /= (find_(x, n_cnt) + 1);
        ADD_(x, n_cnt)
        now_d *= (find_(x, n_cnt) + 1);
    }
}
bool modable(map<int, int>& to_div, map<int, int>& div){
    for(auto it = div.begin(); it!=div.end(); it++){
        if(find_(it->first, to_div) < it->second) return false;
    }
    return true;
}
void solve(){
    int n, q;
    cin>>n>>q;
    now_d = 1;
    n_cnt.clear();
    d_cnt.clear();
    add_decomp(n);
    const int init_dn = now_d;
    const int init_n = n;
    for(int i = 1; i<= q; i++){
        int k;
        cin>>k;
        if(k == 1) {
            int x;
            cin>>x;
            add_decomp(x);
            assign_decomp(now_d, d_cnt);
            if(modable(n_cnt, d_cnt)) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            n = init_n;
            now_d = init_dn;
            n_cnt.clear();
            d_cnt.clear();
            assign_decomp(n, n_cnt);
            assign_decomp(now_d, d_cnt);
        }
    }
}

signed main(){
    #ifndef DEBUG 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #endif
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        solve();
    }
}