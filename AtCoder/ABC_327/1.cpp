#include <bits/stdc++.h>
using namespace std;
#define MAXN 101
char S[MAXN];

signed main(){
    int N;
    cin>>N;
    for(int i = 1 ; i<= N; ++i){
        cin>> S[i];
    }
    bool ans = false;
    for(int i = 1 ; i < N; ++i){
        if(S[i]  == 'a' && S[i + 1] == 'b') ans = true;
        if(S[i]  == 'b' && S[i + 1] == 'a') ans = true;
    }
    if(ans) cout <<"Yes\n";
    else cout << "No\n";
}