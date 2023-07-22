#include <bits/stdc++.h>
using namespace std;
#define int long long

std::map<int,int>EW;//y = k
std::map<int,int>NS;//x = k
std::map<int,int>PX;//x+y = k;
std::map<int,int>NX;//x - y = k;

int cal(int x){
    return x * (x - 1);
}

void insert(int x, std::map<int,int>& map){
    if(map.count(x) == 0){
        map[x] = 1;
    }
    else{
        map[x] ++;
    }
}

void solve(){
    int n;
    EW.clear();
    NS.clear();
    PX.clear();
    NX.clear();
    cin>>n;
    int x,y;
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        insert(y, EW);
        insert(x, NS);
        insert(x+y, PX);
        insert(x-y, NX);
    }
    int ans = 0;
    auto sub_asn = [&](std::map<int,int>& map){
        for(auto iter = map.begin(); iter!=map.end(); iter++){
            ans+= cal(iter->second);
        }
    };
    sub_asn(EW);
    sub_asn(NS);
    sub_asn(PX);
    sub_asn(NX);
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}