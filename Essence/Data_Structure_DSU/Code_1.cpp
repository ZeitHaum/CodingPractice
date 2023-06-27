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
        e[y] += e[x];//注意更新顺序。
        e[x] = y;
        return true;
    }
};

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
