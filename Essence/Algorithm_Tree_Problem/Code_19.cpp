#include <bits/stdc++.h>
using namespace std;
#define MAXN 200'001
#define MAXS 2 
#define MAXK 30
#define MAX_NODE MAXK*MAXN + 1 

struct Trie{
    int node_cnt;//维护Trie树所有结点个数，包含中间结点和叶节点
    int next[MAX_NODE][MAXS];//MANS为可能转移最大的状态数目
    bool bit_map[MAX_NODE];//内存池,表示结点是否存在于已插入的集合中,起始结点为0
    int sons_cont[MAX_NODE];//儿子结点个数,不是必须

    Trie(){
        node_cnt = MAX_NODE;
        clear();
    }

    void clear(){
        for(int i = 0;i<node_cnt;i++){
            for(int j = 0;j<MAXS;j++){
                next[i][j] = -1;//表示非法值
            }
            bit_map[i] = false;
            sons_cont[i] = 0;
        }
        node_cnt = 1;//0号结点一定有
    }
    //插入
    void insert(string& s){
        int p = 0;
        sons_cont[p]++;
        for(int i = 0;i<s.size();i++){
            int now_s = s[i] - '0';//将s状态离散化
            if(next[p][now_s] == -1) next[p][now_s] = node_cnt++;
            p = next[p][now_s];
            sons_cont[p]++;
        }
        bit_map[p] = true;
    }

    //查询
    bool find(string& s){
        int p = 0;
        for(int i = 0;i<s.size();i++){
            int now_s = s[i] - '0';
            if(next[p][now_s] == -1) return false;
            p = next[p][now_s];
        }
        return bit_map[p];
    }
};