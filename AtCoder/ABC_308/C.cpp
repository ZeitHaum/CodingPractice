#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 2e5+2

struct frac{
    int fenzi;
    int fenmu;
    int ind;
    bool operator<(const frac& f) const{
        int a = this->fenzi*(f.fenmu);
        int b = f.fenzi*(this->fenmu);
        if(a==b){
            return this->ind<f.ind;
        }
        return a>b;
    }
};


vector<frac>P(MAXN);
signed main(){
    int N;
    cin>>N;
    for(int i = 1;i<=N;i++){
        cin>>P[i].fenzi>>P[i].fenmu;
        P[i].fenmu += P[i].fenzi;
        P[i].ind = i;
    }
    sort(P.begin()+1, P.begin()+N+1);
    for(int i = 1;i<=N;i++){
        if(i!=1){
            cout<<" ";
        }
        cout<<P[i].ind;
    }
    cout<<"\n";
}