#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

signed main(){
    #ifndef DEBUG
    fast_io();
    #endif
    int N;
    cin >> N;
    vector<int> A(N + 1);
    vector<int> presum(N + 1);
    for(int i = 1; i<=N; ++i){
        cin >> A[i];
    }
    vector<int> B(A.begin(), A.end());
    sort(B.begin() + 1, B.end());
    presum[0] = 0;
    for(int i = 1; i<=N; i++){
        presum[i] = presum[i - 1] + B[i];
    }
    for(int i = 1; i<=N; ++i){
        auto it = upper_bound(B.begin() + 1, B.end(), A[i]);
        if(i!=1) cout << " ";
        if(it == B.end()) cout << "0";
        else {
            int l = it - B.begin();
            cout << presum[N] - presum[l - 1];
        }
    }
    cout << "\n";
}