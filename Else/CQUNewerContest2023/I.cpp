#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, k;
    string T;
    cin>>n>>k;
    cin>>T;
    int now_cnt = 0;
    for(int i = 0; i<T.size(); i++){
        if(T[i] == '1'){
            if(k < i - now_cnt){
                swap(T[i], T[i - k]);
                break;
            }
            else{
                k -= i - now_cnt;
                swap(T[i], T[now_cnt]);
                now_cnt ++;
            }
        }
    }
    // cout<<T<<'\n';
    string ans = "";
    for(int i = 0; i<T.size(); i += 4){
        int tk =  
            (T[i] - '0') * 8 + 
            (T[i + 1] - '0') * 4 + 
            (T[i + 2] - '0') * 2 + 
            (T[i + 3] - '0') * 1; 
        ans.push_back(char('A' + tk));
    }
    cout<<ans<<'\n';
}
/*
10 7
0101111111011000010100111101000011100110
*/