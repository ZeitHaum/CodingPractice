#include <iostream>
#include <algorithm>
#define MAX_SIZE 50001
#define N_INF -1000001
#define P_INF 1000001
using namespace std;

struct S
{
    int mi;
    int mx;
    S():mi(P_INF),mx(N_INF){}
    S(int mi,int mx):mi(mi),mx(mx){}
};

inline S merge(S s1, S s2){
    S ret;
    ret.mi = min(s1.mi,s2.mi);
    ret.mx = max(s1.mx,s2.mx);
    return ret;
}

int da[MAX_SIZE];
S s[4*MAX_SIZE];
S se;

struct seg_tree
{
    void build(int l,int r,int p){
        if(l==r){
            s[p].mi = da[l];
            s[p].mx = da[l];
            return;
        }
        int mid = l+r>>1;
        build(l,mid,p<<1);
        build(mid+1,r,p<<1 | 1);
        s[p] = merge(s[p<<1],s[p<<1 | 1]);
    }

    inline S query(int l,int r,int L,int R,int p){
        if(L<= l && R>=r) return s[p];
        else if(l>R || r<L) return se;
        else{
            int mid = l+r>>1;
            return merge(query(l,mid,L,R,p<<1), query(mid+1,r,L,R,p<<1|1));
        }
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,Q;
    cin>>n>>Q;
    for(int i = 1;i<=n;i++){
        cin>>da[i];
    }
    seg_tree st;
    st.build(1,n,1);
    int L,R;
    for(int i = 1;i<=Q;i++){
        cin>>L>>R;
        S ans = st.query(1,n,L,R,1);
        cout<<ans.mx - ans.mi<<endl;
    }
}