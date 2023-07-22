#include <bits/stdc++.h>
using namespace std;
#define MAXN 51
#define N_INF -1

struct people
{
    int val;
    int ind;
    bool operator<(const people& p) const{
        return this->val < p.val;
    }
};


int a[MAXN];
people b[MAXN];

void solve(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        cin>>b[i].val;
        b[i].ind = i+1;
    }
    for(int i = 0;i<n;i++){
        if(a[i]>10){
            b[i].val = N_INF;
        } 
    }
    sort(b, b+n);
    cout<<b[n-1].ind<<'\n';
}

int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}