#include<bits/stdc++.h>
using namespace std;

struct DSU_size{
    vector<int> e;
    DSU_size(int N){
        e = vector<int>(N,-1);
    }
    int find(int x){return e[x]<0?x:e[x] = find(e[x]);}
    int size(int x){return -e[find(x)];}
    bool check_same(int x,int y){return find(x)==find(y);}
    bool unite(int x,int y){
        x = find(x),y = find(y);
        if(x==y) return false;
        if(e[x]<e[y]) swap(x,y);//小的往大的合入。
        e[y] += e[x];
        e[x] = y;
        return true;
    }
};


//带按尺寸合并和路径压缩
void solve(){
    int n;
    int MAX_SIZE = 10001;
    DSU_size dsu = DSU_size(MAX_SIZE);
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