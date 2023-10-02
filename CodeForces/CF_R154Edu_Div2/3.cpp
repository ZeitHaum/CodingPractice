#include <bits/stdc++.h>
using namespace std;
#define s_get(i) s[i-1]
#define MAXN 20'0001
string s;
int b[MAXN];
int b_ptr = 0;
int n;

bool check(int x){
    if(b[b_ptr]!=-1 &&b[b_ptr]!=x) return false;
    //update
    if(x == 1){
        for(size_t i = b_ptr; i>=1; --i){
            if(b[i]==1) break;
            else if(b[i]==-1) b[i] = 1; 
            else assert(0);
        }
    }
    else if(x == 0){
        if(b_ptr < 2) return false;
        b[b_ptr] = 0;
    }
    return true;
}

void solve(){
    cin>>s;
    n = s.size();
    b_ptr = 0;
    bool ans = true;
    for(size_t i = 1; i<=n; ++i){
        if(s_get(i) == '+') {
            if(b[b_ptr] == 0) b[++b_ptr] = 0;
            else b[++b_ptr] = -1;
        }
        else if(s_get(i) == '-') --b_ptr, ans &= (b_ptr>=0);
        else if(s_get(i) == '1') ans &= check(1);
        else ans &= check(0);
        if(!ans) break;
    }
    if(ans) cout<<"YES\n";
    else cout<<"NO\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    b[0] = -1;
    int t;
    cin>>t;
    for(size_t i = 0;i<t;++i){
        solve();
    }
}