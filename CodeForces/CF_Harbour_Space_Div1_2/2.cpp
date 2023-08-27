#include <bits/stdc++.h>
using namespace std;
int n, k;

void solve(){
    cin>> n>>k;
    string s;
    cin>>s;
    if(k%2==1){
        string odd_s;
        string even_s;
        for(size_t i = 0;i<s.size(); ++i){
            if(i&1) odd_s.push_back(s[i]);
            else even_s.push_back(s[i]);
        }
        sort(odd_s.begin(), odd_s.end());
        sort(even_s.begin(), even_s.end());
        string ret = "";
        for(size_t i = 0; i < odd_s.size();++i){
            ret.push_back(even_s[i]);
            ret.push_back(odd_s[i]);
        }
        if(even_s.size() > odd_s.size()){
            ret.push_back(even_s.back());
        }
        cout<<ret<<'\n';
    }
    else{
        sort(s.begin(), s.end());
        cout<<s<<'\n';
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