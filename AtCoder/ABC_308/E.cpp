#include <bits/stdc++.h>
using namespace std;
#define MAXN 200002
#define int long long
#define find(c,i) (cnt.count(pair<int,int>({s[c],i}))==0? 0: cnt[{s[c],i}])


int A[MAXN];
char S[MAXN];

map<pair<char,int>, int> cnt;

int mex(int v0,int v1,int v2){
    int buff[4] {0};
    buff[v0] = 1;
    buff[v1] = 1;
    buff[v2] = 1;
    for(int i = 0;i<4;i++){
        if(buff[i]==0){
            return i;
        }
    }
    return -1;
}

signed main(){
    int N;
    cin>>N;
    for(int i = 1;i<=N;i++){
        cin>>A[i];
    }
    for(int j = 1;j<=N;j++){
        cin>>S[j];
    }

    for(int i = 1;i<=N;i++){
        if(cnt.count({S[i],A[i]})==0){
            cnt[{S[i],A[i]}] = 1;
        }
        else{
            cnt[{S[i],A[i]}]++;
        }
    }

    string s = "MEX";
    int ans = 0;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            for(int k = 0;k<3;k++){
                int c = find(0,i) * find(1,j) * find(2,k);
                ans += c* mex(i,j,k); 
            }
        }
    }
    cout<<ans<<"\n";

}