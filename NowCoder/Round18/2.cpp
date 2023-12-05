#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool is_prime[21]{
    false, false, true, true,  false, true, // 0 - 5
    false, true, false, false,  false,
    true, false, true, false, false, 
    false, true, false, true, false
};

signed main(){
    fast_io();
    int n;
    cin >> n;
    vector<int> p;
    for(int i = 1; i<=n; i++){
        p.push_back(i);
    }
    int ans = 0;
    bool is_break = false;
    do { 
        bool is_ans = true;
        for(int i = 0; i + 1< p.size(); ++i){
            if(is_prime[p[i] + p[i + 1]]) {
                is_ans = false;
                break;
            }
        }
        if(is_ans) ans ++;
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << '\n';
}