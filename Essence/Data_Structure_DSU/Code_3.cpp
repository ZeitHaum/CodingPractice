#include<bits/stdc++.h>
using namespace std;

struct DSU_rank{
    vector<int>e;
    DSU_rank(int N){e = vector<int>(N,0);}
    int find(int x){return e[x]<=0?x:e[x] = find(e[x]);}
    int rank(int x){return -e[find(x)];}
    bool check_same(int x,int y){return find(x)==find(y);}
    bool unite(int x,int y){
        x = find(x),y = find(y);
        if(x==y) return false;
        if(e[x]<e[y]) swap(x,y);
        e[y] += e[x]==e[y]?0:-1;
        e[x] = y;
        return true;
    }
};


//带按秩合并和路径压缩
void solve(){
    int n;
    int MAX_SIZE = 10001;
    DSU_rank dsu = DSU_rank(MAX_SIZE);
    int actual_size = 0;
    cin>>n;
    int merge_cnt = 0;
    for(int i = 0;i<n;i++){
        int K;
        cin>>K;
        int rep;
        cin>>rep;
        actual_size = max(rep,actual_size);
        int temp;
        for(int j = 1;j<K;j++){
            cin>>temp;
            actual_size = max(temp,actual_size);
            if(dsu.unite(temp,rep)) merge_cnt--;
        }
    }
    int Q;
    cin>>Q;
    int x,y; 
    cout<<actual_size<<" "<<merge_cnt+actual_size<<endl;
    for(int i = 0;i<Q;i++){
        cin>>x>>y;
        if(dsu.check_same(x,y)) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }    
}

int main(){
    solve();
}