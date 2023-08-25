#include <bits/stdc++.h>
using namespace std;

set<int> s;
void solve(){
    int n;
    cin>>n;
    s.clear();
    int tmp;
    int tmp_prexor = 0;    
    for(int i = 0;i<n;i++){
        cin>>tmp;
        s.insert(tmp_prexor ^= tmp);
    }
    int max_val = *s.rbegin();
    for(auto x : s){
        for(auto y : s){
            max_val = max(max_val, x ^ y);
        }
    }
    cout<<max_val<<'\n';
}

int main(){
    int t;cin>>t;
    for(int i = 0;i<t;i++){solve();}
}