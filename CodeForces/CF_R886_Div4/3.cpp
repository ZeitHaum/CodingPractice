#include <bits/stdc++.h>
using namespace std;

enum class State{
    ENABLE = 0, DEFAULT
};

void solve(){
    char map[8][8];
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            cin>>map[i][j];
        }
    }
    int i = 0;
    int j = 0;
    State state = State::DEFAULT;
    string ans = "";
    while (true)
    {
        if(state == State::DEFAULT){
            if(map[i][j]!='.'){
                state = State::ENABLE;
                ans.push_back(map[i][j]);
            }
        }
        else{
            if(map[i][j] == '.'){
                break;
            }
            else{
                ans.push_back(map[i][j]);
            }
        }
        //转移
        if(state==State::DEFAULT){
            j++;
            if(j >= 8){
                j = 0;
                i++;
                if(i>=8){
                    break;
                }
            }
        }
        else{
            i++;
            if(i>=8){
                break;
            }
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}