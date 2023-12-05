#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

#define MAX_SIZE 30'0001
#define MOD 998244353

struct S
{
    int a;
    int b;
    int len;
    S():a(1), b(0), len(0){}
    S(int a,int b, int len):a(a), b(b), len(len){}
    S merge(S s){ 
        S ret;
        ret.a = (a * s.a) % MOD;
        ret.b = (a * s.b) % MOD + b;
        ret.len = len + s.len;
        return ret;
    }
};

int da[MAX_SIZE];
int db[MAX_SIZE];
S s[MAX_SIZE*4];
S se;

struct seg_tree
{
    void build(int l,int r,int p){
        if(l==r){
            s[p] = {da[l],db[l],1};
            return;
        }
        int mid = (l+r)/2;
        build(l,mid,p*2);
        build(mid+1,r,p*2+1);
        s[p] = s[p*2].merge(s[p*2+1]);
    }

    S query(int l,int r,int p,int L,int R){
        if(L<= l && R>=r) return s[p];
        else if(l>R || r<L) return se;
        else{
            int mid = (l+r)/2;
            return query(l,mid,p*2,L,R).merge(query(mid+1,r,p*2+1,L,R));
        }
    }
};

int qpow(long long a, int b) {
    int ans = 1;
    a = (a % MOD + MOD) % MOD;
    for (; b; b >>= 1) {
        if (b & 1) ans = (a * ans) % MOD;
        a = (a * a) % MOD;
    }
    return ans;
}

int find_inv(int a){
    return qpow(a, MOD - 2);
}

signed main(){
    int n;
    cin >> n;
    for(int i = 1; i<= n; ++i){
        cin >> da[i];
    }
    for(int i = 1; i<=n; ++i){
        cin >> db[i];
    }
    int q;
    cin>> q;
    seg_tree st;
    st.build(1, n, 1);
    int l, r, y;
    for(int i = 1; i<=q; ++i){
        cin>>l >> r >> y;
        S ans = st.query(1, n, 1, l, r);
        if(ans.a == 0) cout << numeric_limits<int>::infinity() << '\n';
        else cout << ((y - ans.b + MOD) % MOD * find_inv(ans.a)) % MOD << "\n";
    }
}