#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

signed main(){
    #ifndef DEBUG
    fast_io();
    #endif
    int n;
    cin >> n;
    vector<int> buk(101, 0);
    int tmp;
    for(int i = 1; i<=n; ++i){
        cin >> tmp;
        buk[tmp] = 1;
    }
    bool nofirst = false;
    for(int i = 100; i>=1; --i){
        if(buk[i] && !nofirst) {
            nofirst  = true;
            continue;
        } 
        else if(buk[i] && nofirst){
            cout << i << "\n";
            return 0;
        }
    }
}