#include<bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream& out,const vector<int>& arr){
    for(int i = 0;i<arr.size();i++){
        out<<arr[i]<<" ";
    }
    return out;
}
ostream& operator<<(ostream& out,const vector<bool>& arr){
    for(int i = 0;i<arr.size();i++){
        out<<arr[i]<<" ";
    }
    return out;
}
ostream& operator<<(ostream& out,const pair<int,int>& p){
    out<<p.first<<","<<p.second<<" ";
    return out;
}
ostream& operator<<(ostream& out,const map<pair<int,int>,int>& dic){
    for(auto iter = dic.begin();iter!=dic.end();iter++){
        out<<iter->first<<":"<<iter->second<<" ";
    }
    return out;
}

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