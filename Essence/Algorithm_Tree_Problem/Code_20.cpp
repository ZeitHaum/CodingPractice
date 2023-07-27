#include <bits/stdc++.h>
using namespace std;
#define MAXN 200'001
#define MAXS 2
#define MAXK 31
#define MAXNODE MAXK * MAXN

int VALID_MASK = 0x7fff'ffff;
int n, k;
int da[MAXN];

struct ans_pair{
    int a;
    int b;
};

vector<ans_pair> Ans;

struct Trie{
    int node_cnt;//维护Trie树所有结点个数，包含中间结点和叶节点
    int next[MAXNODE][MAXS];//MANS为可能转移最大的状态数目
    bool bit_map[MAXNODE];//内存池,表示结点是否存在于已插入的集合中,起始结点为0
    int sons_cont[MAXNODE];//儿子结点个数

    Trie(){
        node_cnt = MAXNODE;
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
    //return: ans_part
    int dfs(int p, int now_val){
        if(p==-1){
            //invalid node
            return -1;
        }
        if(sons_cont[p] == 2 && next[p][0]!=-1 && next[p][1]!=-1){
            int tmp_a = dfs(next[p][0], (now_val<<1));
            int tmp_b = dfs(next[p][1], (now_val<<1) | 1);
            Ans.push_back({tmp_a, tmp_b});
        }
        else if(sons_cont[p] >=2){
            dfs(next[p][0], (now_val<<1));
            dfs(next[p][1], (now_val<<1) | 1);
        }
        else if(sons_cont[p] == 1){
            //1
            if(bit_map[p]==true){
                return now_val;
            }
            else{
                int a = dfs(next[p][0], (now_val<<1));
                int b = dfs(next[p][1], (now_val<<1) | 1);
                return a == -1? b : a;
            }
        }
        //0
        return -1;
    }
};

Trie trie;//声明于静态内存区，避免爆栈

int f(int x, int y){
    return ~((x & VALID_MASK)^(y & VALID_MASK)) & VALID_MASK;
}

void init_valid_mask(){
    VALID_MASK = (0x7fff'ffff >> (31 - k));
}

int calc_x(int a, int b){
    int ret = 0;
    string bin_ret = "";
    for(int i = 0;i<k;i++){
        if((a&1) && (b&1)){
            bin_ret.push_back('0');
        }
        else if(!(a&1) && !(b&1)){
            bin_ret.push_back('1');
        }
        else{
            bin_ret.push_back('0');
        }
        a = a/2;
        b = b/2;
    }
    reverse(bin_ret.begin(), bin_ret.end());    
    for(int i = 0;i<k;i++){
        if(bin_ret[i] == '1'){
            ret += 1;
        }   
        if(i!=k-1){
            ret = ret<<1;
        }
    }
    return ret;
}

string dec_to_bin(int x){
    string s = "";
    for(int i = 0;i<k;i++){
        s+= (x%2==0)?"0":"1";
        x = x/2;
    }
    reverse(s.begin(), s.end());
    return s;
}

void solve(){
    cin>>n>>k;
    trie.clear();
    Ans.clear();
    init_valid_mask(); 
    bool is_all_same = false;
    std::map<int,int> val2ind;
    int same_ind = -1;
    for(int i = 0;i<n;i++){
        cin>>da[i];
        if(is_all_same){
            continue;
        }
        string da_bin = dec_to_bin(da[i]);
        if(trie.find(da_bin)== true){
            is_all_same = true;
            same_ind = i;
        }
        else{
            val2ind.insert({da[i], i+1});
            trie.insert(da_bin);
        }
    }
    //case1:duplicated
    if(is_all_same){
        cout<<same_ind+1 << " "<<val2ind[da[same_ind]] <<" "<< calc_x(da[same_ind], da[same_ind])<<"\n";
        return;
    }
    //case2
    trie.dfs(0, 0);
    int ans_a, ans_b, ans_x, ans = -1;
    for(int i = 0;i<Ans.size();i++){
        if(ans<f(Ans[i].a, Ans[i].b)){
            ans_a = Ans[i].a;
            ans_b = Ans[i].b;
            ans = f(Ans[i].a, Ans[i].b);
        }
    }
    cout<<val2ind[ans_a]<<" "<<val2ind[ans_b]<<" "<<calc_x(ans_a, ans_b)<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}
