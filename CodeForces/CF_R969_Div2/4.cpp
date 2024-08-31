#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int buk[200001];

void solve(){
    int n;
    cin >> n;
    memset(buk+1, 0, n*sizeof(int));
    int root_weight = -1;
    int leaf_undef = 0;
    int unleaf = 0;
    int leaf_0 = 0;
    int leaf_1 = 0;
    int x, y;
    for(int i = 0; i<n - 1; ++i){
        cin >> x >> y;
        buk[x]++;
        buk[y]++;
    }
    char w;
    for(int i = 1; i<=n; ++i){
        cin >> w;
        if(i==1){
            if(w=='1' || w=='0'){
                root_weight=int(w - '0');
            }
        }
        else{
            if(buk[i]==1){
                //Leaf
                if(w=='0'){
                    leaf_0++;
                }
                else if(w=='1'){
                    leaf_1++;
                }
                else{
                    leaf_undef++;
                }
            }
            else if(w == '?'){
                unleaf++;
            }
        }
    }
    if(root_weight == 0){
        cout << leaf_1 + (leaf_undef + 1) /2 << "\n";
    }
    else if(root_weight == 1) {
        cout << leaf_0 + (leaf_undef + 1) / 2 << "\n";
    }
    else {
        if(leaf_0 != leaf_1){
            cout << max(leaf_0, leaf_1) + leaf_undef / 2 << '\n';
        }
        else{
            if(unleaf & 1){
                cout << leaf_0 + (leaf_undef+1) / 2 << '\n';
            }
            else{
                cout << leaf_0 + leaf_undef  / 2<< '\n';
            }
        }
    }
}

signed main(){
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(int i = 0; i <t; ++i){
        solve();
    }
}