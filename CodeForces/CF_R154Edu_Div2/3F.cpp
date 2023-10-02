#include <bits/stdc++.h>
using namespace std;
// #define DEBUG
#define MAXN 20'0001
string s;
int n;
int next_01[MAXN];
int now_size;
map<int, char> memory_01;
int pre_and = 1;

char s_get(int i){
    return s[i - 1];
}

enum class CheckType{OO = 0, OI = 1, IO = 2, II = 3};

void init_next_01(){
    int last_ind = 0;
    for(size_t i = 1; i<=s.size(); ++i){
        if(s_get(i) == '1') next_01[last_ind] = i, last_ind = i;
        else if(s_get(i) == '0') next_01[last_ind] = i, last_ind = i;
    }
    next_01[last_ind] = n+1;
    #ifdef DEBUG
        for(size_t i = 0; i<=n;++i){
            cout<<next_01[i]<<" ,";
        }
        cout<<"\n";
    #endif
}

bool check_(int l, int r, CheckType ct){
    if(ct == CheckType::II){
        for(size_t i = l; i<=r; ++i){
            if(s_get(i) == '+') ++now_size;
            else if(s_get(i) == '-') --now_size;
            if(now_size<0) return false;
        }
        return true;
    }
    else if(ct == CheckType::OO){
        for(size_t i = l;i<=r; ++i){
            if(now_size < 2) return false;
            if(s_get(i) == '+') ++now_size;
            else if(s_get(i) == '-') --now_size;
        }
        return true;
    }
    else if(ct == CheckType::IO){
        bool has_1 = false;
        for(size_t i = l;i<=r; ++i){
            if(s_get(i) == '+') ++now_size, has_1 = true;
            else if(s_get(i) == '-') --now_size;
            if(now_size<0) return false;
        }
        #ifdef DEBUG
            cout<<now_size<<", "<< has_1;
        #endif
        return now_size >= 2 && has_1;
    }
    else{
        int min_delta = 0;
        const int begin_size = now_size;
        for(size_t i = l; i<=r; ++i){
            if(s_get(i) == '+') ++now_size;
            else if(s_get(i) == '-') --now_size;
            if(now_size < 0) return false;
            min_delta = min(min_delta, now_size - begin_size);   
        }
        #ifdef DEBUG
            cout<<now_size<<",OI,"<<min_delta<<'\n';
        #endif
        return now_size>=0 && min_delta<0;
    }
    return false;
}

CheckType get_ct(char l, char r){
    return (CheckType)((l - '0')*2 + (r - '0'));
}

bool check_lr(int l, int r){
    if(l == 0){
        bool ret;
        if(s_get(r) == '0') ret = check_(l+1, r-1, CheckType::IO);
        else ret =  check_(l+1, r-1, CheckType::II);
        memory_01.insert({now_size, s_get(r)});
        return ret;
    }
    // if(s_get(l) == '0' && s_get(r) == '0') return check_(l+1, r-1, CheckType::OO);
    // else if(s_get(l) == '0' && s_get(r) == '1') return check_(l+1, r-1, CheckType::OI);
    // else if(s_get(l) == '1' && s_get(r) == '0') return check_(l+1, r-1, CheckType::IO);
    // else return check_(l+1, r-1, CheckType::II);
    // return false;
    int now_c_size = now_size;
    bool ret = true;
    int last_ck_lind = l;
    char last_ck_c = s_get(last_ck_lind);
    for(size_t i = l; i <= r; i ++){
        if(l>n) break;
        if(s_get(i) == '+') ++now_c_size;
        else if(s_get(i) == '-') --now_c_size;
        if(!memory_01.empty() && now_c_size == prev(memory_01.end())->first){
            ret &= check_(last_ck_lind+1, i, get_ct(last_ck_c, memory_01[now_c_size]));
            last_ck_lind = i;
            last_ck_c = memory_01[now_c_size];
        }
        else if(!memory_01.empty() && now_c_size == prev(memory_01.end())->first - 1){
            memory_01.erase(now_c_size + 1);
        }
    }
    if(r<=n && !memory_01.empty() && now_c_size == prev(memory_01.end())->first){
        ret &= (memory_01[now_c_size] == s_get(r));
    }
    else if(r == n+1 && last_ck_lind< n) ret &= check_(last_ck_lind+1, n, CheckType::II);
    else if(r < n+1) ret &= check_(last_ck_lind+1, r, get_ct(last_ck_c, s_get(r)));
    if(r < n+1) {
        memory_01.insert({now_c_size, s_get(r)});
    }
    return ret;
}

bool check_end(int l){
    return check_lr(l+1, n + 1);
}

void solve(){
    s.clear();
    cin>>s;
    n = s.size();
    now_size = 0;
    memory_01.clear();
    init_next_01();
    int now_l = 0, now_r = next_01[now_l];
    bool ans = true;
    while(now_r <= n){
        if(!check_lr(now_l, now_r)){
            ans = false;
            break;
        }
        else{
            now_l = now_r;
            now_r = next_01[now_r];
        }
    }
    ans = ans & check_end(now_l);
    if(ans) cout<<"YES\n";
    else cout<<"NO\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(size_t i = 0;i<t;++i){
        solve();
    }
}
/*
1
++0-+1-+0
*/