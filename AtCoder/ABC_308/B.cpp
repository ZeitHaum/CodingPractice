#include <bits/stdc++.h>
using namespace std;

map<string, int> f;

int main(){
    int N,M;
    cin>>N>>M;
    vector<string> data(N);
    for(int i = 0;i<N;i++){
        cin>>data[i];
    }
    vector<string>Key(M);
    vector<int>Value(M);
    for(int i = 0;i<M;i++){
        cin>>Key[i];
    }
    int none = 0;
    cin>>none;
    for(int i = 0;i<M;i++){
        cin>>Value[i];
        f[Key[i]] = Value[i];
    }
    int ans = 0;
    for(int i = 0;i<N;i++){
        if(f.count(data[i])!=0){
            ans += f[data[i]];
        }
        else{
            ans +=none;
        }
    }
    cout<<ans<<"\n";
}