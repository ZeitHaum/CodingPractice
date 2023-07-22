#include <bits/stdc++.h>
using namespace std;

#define MAXN (200*1000 + 1)

struct Interval
{
    int l;
    int r;
};

int da[MAXN];
std::vector<Interval> ans;
enum class State{
    ININT = 0, END
};


void solve(){
    int n,k;
    cin>>n>>k;
    for(int i =0;i<n;i++){
        cin>>da[i];
    }
    sort(da, da+n);
    State s = State::ININT;
    ans.clear();
    for(int i = 0;i<n;i++){
        if(i==n-1 || da[i+1] - da[i] >k){
            s = State::END;
        }
        else{
            s = State::ININT;
        }
        if(s == State::ININT){

        }
        else{
            ans.push_back({ans.empty()?0:ans.back().r + 1, i});
        }
    }
    int max_len = 0;
    for(int i = 0;i<ans.size();i++){
        max_len = max(max_len, ans[i].r - ans[i].l + 1);
    }
    cout<<n - max_len<<"\n";
}

int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}