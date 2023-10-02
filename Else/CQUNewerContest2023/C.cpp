#include <bits/stdc++.h>
using namespace std;
#define MAXN 2001
char ans[MAXN][MAXN];

map<char, char> next_begin_color { 
    {'R', 'B'},
    {'B', 'G'},
    {'G', 'R'}
};

map<char, char> next_color{
    {'R' , 'G'},
    {'G', 'B'},
    {'B', 'R'}
};

signed main(){
    int n, m;
    cin>>n>>m;
    char now_begin = 'R';
    for(int i = 1; i <= n; i++){
        if(i != 1) now_begin = next_begin_color[now_begin];
        char now = now_begin;
        for(int j = 1; j<= m; j++){
            if(j != 1 ) now = next_color[now];
            ans[i][j] = now; 
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j<= m; j++){
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
}