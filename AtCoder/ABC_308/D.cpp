#include <bits/stdc++.h>
using namespace std;
#define MAXS 501
#define check(x,y) (map_[i][j] == next_[map_[x][y]])
#define point pair<int,int>

char map_[MAXS][MAXS];
int dp[MAXS][MAXS];
map<char,char> next_{{'s','n'},{'n','u'},{'u','k'},{'k','e'},{'e','s'}};

map<point,set<point>> adj;
map<point, bool> vis;

int main(){
    int H,W;
    cin>>H>>W;
    for(int i = 1;i<=H;i++){
        for(int j = 1;j<=W;j++){
            cin>>map_[i][j];
            vis[{i,j}] = false;
        }
    }
    for(int i = 1;i<=H;i++){
        for(int j = 1;j<=W;j++){
            if(i!=1 && check(i-1, j)){
                adj[{i-1,j}].insert({i,j});
            }
            if(j!=1 && check(i,j-1)){
                adj[{i,j-1}].insert({i,j});
            }
            if(i!=H && check(i+1,j)){
                adj[{i+1,j}].insert({i,j});
            }
            if(j!=W && check(i,j+1)){
                adj[{i,j+1}].insert({i,j});
            }
        }
    }
    
    point begin = {1,1};
    queue<point> q;
    q.push(begin);
    bool ans = false;
    vis[begin] = true;
    while(!q.empty()){
        point qf = q.front();
        if(qf==point(H,W)){
            ans = true;
            break;
        }
        for(auto p: adj[qf]){
            if(vis[p]==false){
                q.push(p);
                vis[p] = true;
            }
        }
        q.pop();
    }
    if(ans){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}

