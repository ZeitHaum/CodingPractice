#include <bits/stdc++.h>
using namespace std;
 
bool buk[10000001]{false};
vector<int> primes(0);
map<int,int> cnts;
map<int,int> isprimes;
 
void solve(){
    int n;
    cin>>n;
    int ans = 0;
    int tmp;
    auto add = [&](int x){
        if(isprimes.count(x) != 0){
            cnts[x] ++;
            return;
        }
        for(int i = 0;i<primes.size();i++){
            while(x >0 && x%primes[i]==0){
                if(cnts.count(primes[i])==0){
                    cnts[primes[i]] = 1;
                }
                else cnts[primes[i]]++;
                x = x/primes[i];
                if(isprimes.count(x)!=0){
                    cnts[x]++;
                    x = 0;
                    break;
                }
            }
            if(x==0) break;
        }
    };
    for(int i = 1;i<=n;i++){
        cin>>tmp;
        add(tmp);
    }
    int cnt = 0;
    for(auto iter = cnts.begin();iter!=cnts.end();iter++){
        ans += iter->second/2;
        cnt += iter->second%2;
    }
    cout<<ans + cnt/3<<"\n";
    cnts.clear();    
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 2;i<=10000000;i++){
        if(buk[i]==true) continue;
        int now = i*2;
        while(now<=10000000){
            buk[now] = true;
            now = now + i;
        }
    }
    for(int i = 2;i<=10000000;i++){
        if(buk[i]==false){
            primes.push_back(i);
            isprimes[i] = 1;
        }
    }
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}