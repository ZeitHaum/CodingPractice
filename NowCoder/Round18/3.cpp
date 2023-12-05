#include <bits/stdc++.h>
using namespace std;

#define MAXN 10'0001
int da[MAXN];

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


map<int, int> cnt;

inline void add(map<int, int> & cnt, int x){
    if(cnt.find(x) == cnt.end()) cnt[x] = 1;
    else cnt[x] ++;
}

inline int get(map<int, int> & cnt, int x){
    if(cnt.find(x) == cnt.end()) return 0;
    else return cnt[x];
}

signed main(){
    fast_io();
    int n, k;
    cin >> n >> k;
    for(int i = 1; i<=n; ++i){
        cin>> da[i];
        add(cnt, da[i] % k); 
    }
    int ans = 0;
    for(auto & it : cnt){
        if(it.first == 0) ans += it.second;
        if(it.first > k / 2) break;
        else if(it.first == k/ 2 && !(k & 1)) ans += it.second / 2;
        else {
            ans += min(it.second, get(cnt, k - it.first));
        }
    }
    cout << ans << '\n';
}