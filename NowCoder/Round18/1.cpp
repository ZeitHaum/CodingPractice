#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

signed main(){
    string s;
    int k;
    cin>> s >> k;
    reverse(s.begin(), s.begin() + k);
    cout << stoi(s) << '\n';
}