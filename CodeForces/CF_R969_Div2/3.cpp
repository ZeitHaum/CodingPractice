    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;

    vector<int> modts;

    void solve(){
        modts.clear();
        int n, a, b;
        cin >> n >> a >> b;
        int gcd_ = __gcd(a, b);
        int max_g = INT32_MIN;
        int min_g = INT32_MAX;
        int ta;
        for(int i = 1; i<=n; ++i){
            cin >> ta;
            int modt = ta % gcd_;
            max_g = max(max_g, modt);
            min_g = min(min_g, modt);
            modts.push_back(modt);
        }
        int ans = max_g - min_g;
        sort(modts.begin(), modts.end());
        for(int i = 0; i+1<modts.size(); ++i){
            ans = min(ans, modts[i] + gcd_ - modts[i+1]);
        }
        cout << ans << "\n";
    }

    signed main(){
        int t;
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        cin>>t;
        modts.reserve(100001);
        for(int i = 0; i <t; ++i){
            solve();
        }
    }