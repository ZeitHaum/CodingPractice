#include <bits/stdc++.h>
using namespace std;

int main(){
    int S[8];
    for(int i = 0;i<8;i++){
        cin>>S[i];
    }
    //cond 1
    bool sat = true;
    for(int i = 1;i<8;i++){
        if(S[i-1]>S[i]){
            sat = false;
            break;
        }
    }
    for(int i = 1;i<8;i++){
        if(S[i]>675 || S[i]<100 || S[i] % 25!=0){
            sat = false;
            break;
        }
    }
    if(sat){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}