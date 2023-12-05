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
    string s;
    cin >> s;
    for(int i = 0; i< s.size(); ++i){
        if(i !=0) cout << " ";
        cout << s[i];
    }
    cout << '\n';
}