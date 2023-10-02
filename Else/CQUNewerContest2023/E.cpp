#include <bits/stdc++.h>
using namespace std;
#define MAXN 21
int card_num[MAXN];
char card_col[MAXN];
#define NO() {cout<<"No\n"; return 0;}
#define YES() {cout<<"Yes\n"; return 0;}
signed main(){
    int n;
    cin>>n;
    for(int i = 1; i<= n; i++){
        cin>>card_num[i];
        if(card_num[i] == 2) cin>> card_col[i];
    }
    //Check
    int cnt4 = 0;
    map<char, int> cnt2 {
        {'R', 0},  
        {'G', 0},  
        {'Y', 0},  
        {'B', 0}
    };
    for(int i = 1; i<=n; i++){
        cnt4 += (int)(card_num[i] == 4);
        if(card_num[i] == 2) cnt2[card_col[i]] ++;
    }
    if(cnt4 > 4) NO()
    if(cnt2['R'] > 2 || 
       cnt2['G'] > 2 ||
       cnt2['B'] > 2 ||
       cnt2['Y'] > 2
    ) NO()
    for(int i = 2; i<=n; i++){
        if(card_num[i - 1] == 4 && card_num[i]!=4) NO() 
    }
    YES()
} 
/*
5
2 R
2 G
4
4
4
*/