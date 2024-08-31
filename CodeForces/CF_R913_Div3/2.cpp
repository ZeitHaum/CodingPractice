#include <bits/stdc++.h>
using namespace std;

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


void solve(){
    string s;
    cin >> s;
    vector<bool> ans_mask(s.size(), 1);
    stack<int> low_st;
    stack<int> up_st;
    for(int i = 0; i<s.size(); ++i){
        if(s[i] == 'B'){
            if(!up_st.empty())
            {
                ans_mask[up_st.top()] = 0;
                up_st.pop();
            }
        }
        else if(s[i] == 'b'){
            if(!low_st.empty()){
                ans_mask[low_st.top()] = 0;
                low_st.pop();
            }
        }
        else{
            if(s[i]>= 'a' && s[i] <= 'z'){
                low_st.emplace(i);
            }
            else up_st.emplace(i);
        }
    }
    string ans = "";
    for(int i = 0; i<s.size(); ++i){
        if(s[i] !='B' && s[i] != 'b' && ans_mask[i] == 1){
            ans.push_back(s[i]);
        }
    }
    cout << ans << "\n";
}

signed main(){
    #ifndef DEBUG
    fast_io();
    #endif
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        solve();
    }
}