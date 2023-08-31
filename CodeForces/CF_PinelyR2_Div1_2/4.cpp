#include <bits/stdc++.h>
using namespace std;
#define MAXN 501
int n, m;
char map_[MAXN][MAXN];
char ans_[MAXN][MAXN];

bool check_row[MAXN];
bool check_column[MAXN];

int ans_row[MAXN];
int ans_column[MAXN];

enum class PaintType {Horizontal = 0, Vertical};

char col_opposite(char c){
    if(c == '.') return '.';
    else if(c == 'B') return 'W';
    else if(c == 'W') return 'B';
    return '$';
}

void paintCell(const int& i,const int& j, char c){
    if(c == 'W'){
        ans_[i][j] = 'W';
        ans_row[i]++;
        ans_column[j]++;
    }
    else if(c == 'B'){
        ans_[i][j] = 'B';
        ans_row[i]--;
        ans_column[j]--;
    }
}

void paint(int i, int j, PaintType pt){
    if(pt == PaintType::Horizontal){
        if(ans_column[j] <= 0) paintCell(i, j, 'W');
        else paintCell(i, j, 'B');
        paintCell(i, j+1, col_opposite(ans_[i][j]));
    }
    else{
        if(ans_row[i] <= 0) paintCell(i, j, 'W');
        else paintCell(i, j, 'B');
        paintCell(i+1, j, col_opposite(ans_[i][j]));
    }
    // cerr<<i<<", "<<j<<", "<<(int)pt<<","<<ans_[i][j] <<", "<<ans_[min(i+1, n)][j]<<", "<<ans_[i][min(j+1, m)]<<"\n";
}

bool check(){
    for(size_t i = 1; i<=n; ++i){
        // cerr<< check_row[i]<<',';
        if(check_row[i]) return false;
    }
    // cerr<<"\n";
    for(size_t i = 1; i<=m; ++i){
        // cerr<< check_column[i]<<',';
        if(check_column[i]) return false;
    }
    return true;
}

void solve(){
    cin >> n >> m;
    //Black -1, White 1;
    for(size_t i = 1; i<=n; ++i) check_row[i] = false, ans_row[i] = 0;
    for(size_t i = 1; i<=m; ++i) check_column[i] = false, ans_column[i] = 0;
    for(size_t i = 1; i <= n; ++i){
        for(size_t j = 1; j <= m; ++j){
            cin>>map_[i][j];
            if(map_[i][j] == '.') ans_[i][j] = '.';
            else {
                ans_[i][j] = '$';
                check_row[i] ^= true;
                check_column[j] ^= true;
            }
        }
    }
    if(!check()){
        cout<< -1 <<'\n';
        return;
    }
    // fill L, R
    for(size_t j = 1; j<=m - 1; ++j){
        for(size_t i = 1; i<= n; ++i){
            if(map_[i][j] == 'L') {
                paint(i, j, PaintType::Horizontal);
            }
        }
    }
    // fill U, D
    for(size_t i = 1; i<= n - 1; ++i){
        for(size_t j = 1; j<= m; ++j){
            if(map_[i][j] == 'U'){
                paint(i, j, PaintType::Vertical);
            }
        }
    }
    for(size_t i = 1; i<= n; ++i){
        for(size_t j = 1; j<= m; ++j){
            cout<<ans_[i][j];
        }
        cout<<'\n';
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(size_t i = 0;i<t;++i){
        solve();
    }
}