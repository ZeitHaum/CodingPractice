#include <bits/stdc++.h>
using namespace std;
#define MAXN 200'001
#define int long long

int n, k;
int a[MAXN];
int low_cnt[MAXN];


int low(int j){
    int pos = lower_bound(low_cnt + 1, low_cnt+n+1, j) - low_cnt;
    return j + pos - 1;
}

void solve(){
    cin>>n>>k;
    int tmp;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    for(int i = 1;i<=n;i++){
        low_cnt[i] = a[i] - i;
    }
    int i = k, j = 1;
    while (true)
    {
        i = i - 1;
        j = low(j);
        if(i==0){
            break;
        }
    }
    cout<<j<<"\n";
}

signed main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}
/*
1
5 1
1 2 4 5 6
*/