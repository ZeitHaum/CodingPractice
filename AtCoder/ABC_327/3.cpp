#include <bits/stdc++.h>
using namespace std;
#define int long long

int nums[10][10];
int buk[10];

inline bool check(){
    for(int i = 1; i<=9; ++i){
        if(buk[i] == 0) return false;
    }
    return true;
}

inline void clear(){
    for(int i = 1; i<=9; ++i){
        buk[i] = 0;
    }
}

signed main(){
    for(int i = 1; i<= 9; i ++ ){
        for(int j = 1; j <= 9; j++){
            cin>>nums[i][j];
        }
    }
    int ans = true;
    for(int i = 1; i<= 9; i ++){
        // row
        clear();
        for(int j = 1; j<=9; j++){
            buk[nums[i][j]] = 1;
        }
        ans &= check();
    }
    for(int j = 1; j <= 9; j++){
        clear();
        for(int i = 1; i<=9; i++){
            buk[nums[i][j]] = 1;
        }
        ans &= check();
    }
    for(int i = 1; i<= 3; ++i){
        for(int j = 1; j <= 3; ++j){
            int x = 1 + 3 * (i - 1);
            int y = 1 + 3 * (j - 1);
            clear();
            for(int ii = 0; ii<=2;ii++){
                for(int jj = 0; jj <= 2; jj++){
                    buk[nums[x + ii][y + jj]] = 1;
                }
            }
            ans &= check();
        }
    }
    if(ans) cout << "Yes\n";
    else cout << "No\n";
}