#include <bits/stdc++.h>
using namespace std;
#define int long long

int pow_(int a, int x){
    int ans = 1;
    while(x!=0){
        ans *= a;
        --x;
    }
    return ans;
}

signed main(){
    int B; 
    cin>>B;
    if(B == 1) cout << B << "\n";
    else{
        int ans = -1;
        for(int i = 1; i<=16; i++){
            if(pow_(i, i) == B) {
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }
}