#include <bits/stdc++.h>
using namespace std;

string s;

signed main(){
    int n, m;
    cin>>n>>m;
    string tmp_s;
    for(int i = 1; i<=n; i++){
        cin>>tmp_s;
        s.append(tmp_s);
    }
    int x0, y0, x, y;
    cin>>x0 >> y0 >> x >> y;
    int begin_pos = m * (x0 - 1) + (y0 - 1);
    vector<int> ans;
    bool vis[101];
    for(int i = 1; i<=100; i++){
        vis[i] = false;
    }
    for(int i = begin_pos; i + 1 < s.size(); i+=2){
        int tx = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if(!vis[tx] && tx >= 1 && tx<=x){
            ans.push_back(tx);
            vis[tx] = true;
        }
        if(ans.size() == y){
            break;
        }
    }
    if(ans.size() == y){
        for(auto it = ans.begin(); it!= ans.end(); it++){
            if(it != ans.begin()) cout<<' ';
            cout<<*it;
        }
        cout<<'\n';
    }
    else cout<<"-1\n";
}
/*
6 10
0347437386
3696473661
4699698162
9774246762
4281145720
4253323732
2 1 99 10
*/