#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n, m , k;
    cin>>n>>m>>k;
    int left = n + m;
    if(!(k & 1)){
        left -= n - (n % k);
        n %= k;
        if(n & 1) --n;
        //安排男女混
        if(n + 2*m >= k) {
            m -= (k - n) / 2;
            left -= (n + (k - n) / 2);
        }
        //安排全女
        if(2 *m >= k){
            left -= (m - m % (k / 2));
        }
        cout<<left << '\n';
    }   
    else{   
        //安排男女混
        int round =  min(n, k==1? n+1 : (m*2)/(k - 1));
        n -= round;
        m -= (k - 1) /2 * round;
        left -= (1 + (k - 1)/ 2) * round;
        // while(true){
        //     if(n == 0) break;
        //     if(m * 2 < k - 1) break;
        //     n --;
        //     m -= (k - 1)/2;
        //     left -= (1 + (k - 1)/2);
        // }
        //最后一组男女混
        if(n > max(k - 2*m, 0LL)){
            n -= k - 2*m;
            left -= m + (k - 2*m);
        }
        if(n > 0){
            left -= n - (n % k);
        }
        cout<<left<<"\n";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    for(int i = 1; i<= T; ++i){
        solve();
    }
}   