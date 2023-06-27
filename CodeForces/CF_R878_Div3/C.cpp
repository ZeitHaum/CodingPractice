#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX_N 2e5+1

//count consecutive days 
int count_cdays(int len,const int& k){
    if(len<k) return 0;
    else return (len-k+2)*(len-k+1)/2;//only calc [k,len]
}

vector<int> temperature(MAX_N);

void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    int state = 0;//0 for above and 1 for below(include Eq)
    int sub_len = 0;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        cin>>temperature[i];
        if(state==0){
            if(temperature[i]<=q){
                state = 1;
                sub_len = 1;
            }
            else{
                state = 0;
            }
        }
        else{
            if(temperature[i]<=q){
                state = 1;
                sub_len++;
            }else{
                state = 0;
                if(sub_len>=k){
                    ans+= count_cdays(sub_len,k);
                }
                sub_len = 0;
            }
        }
    }
    if(state==1){
        state = 0;
        if(sub_len>=k){
            ans+= count_cdays(sub_len,k);
        }
        sub_len = 0;
    }
    cout<<ans<<"\n";
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