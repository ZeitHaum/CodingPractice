#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ret ="";
    char now = '-';
    for(int i = 0;i<s.size();i++){
        if(now == '-'){
            now = s[i];
        }
        else if(s[i]==now){
            ret.push_back(s[i]);
            now = '-';
        }
    }
    cout<<ret<<"\n";
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