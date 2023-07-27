#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MAXN 200'001
int da[MAXN];
int de_da[MAXN];
multiset<int> de_parse;
multiset<int> per;

void solve(){
    int n;
    cin>>n;
    de_parse.clear();
    per.clear();
    for(int i = 1;i<=n-1;i++){
        cin>>da[i];
        de_da[i] = i==1? da[i]: da[i] - da[i-1];
        de_parse.insert(de_da[i]);
    }
    for(int i = 1;i<=n;i++){
        per.insert(i);
    }
    for(int i = 1;i<=n-1;i++){
        if(per.find(de_da[i])!= per.end()){
            per.erase(per.find(de_da[i]));
            de_parse.erase(de_parse.find(de_da[i]));
        }
    }
    bool check = false;
    if((de_parse.size() == 1) && (per.size() == 2)){
        int p = *de_parse.begin();
        auto de_pa = per.begin();
        int p_a = *de_pa;
        de_pa++;
        int p_b = *de_pa;
        check = (p_a + p_b == p);
    }
    else if((de_parse.size() == 0) && (per.size() == 1)){
        check = true;
    }
    if(check){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

signed main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}