#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX_SIZE 100001

int p;
struct S
{
    int val;
    int len;
    S():val(0),len(0){}
    S(int val,int len):val(val),len(len){}
    S merge(S s){ return {(this->val+s.val)%p,this->len+s.len};}
};

struct F
{
    int add;
    int mul;
    F():add(0),mul(1){}
    F(int add,int mul):add(add),mul(mul){}
    F composition(F f){ return {((this->add*f.mul)%p + f.add)%p,(this->mul*f.mul)%p};}
};

S apply(F f, S s){
    return {((s.val * f.mul)%p + (s.len * f.add)%p)%p,s.len};
}

int da[MAX_SIZE];
S s[MAX_SIZE*4];
F lazy[MAX_SIZE*4];
S se;
F fe;

struct seg_tree
{
    void build(int l,int r,int p){
        if(l==r){
            s[p] = {da[l],1};
            return;
        }
        int mid = (l+r)/2;
        build(l,mid,p*2);
        build(mid+1,r,p*2+1);
        s[p] = s[p*2].merge(s[p*2+1]);
    }

    void push_down(int p){
        lazy[p*2] =  lazy[p*2].composition(lazy[p]);
        lazy[p*2+1] = lazy[p*2+1].composition(lazy[p]);
        s[p*2] = apply(lazy[p],s[p*2]);
        s[p*2+1] = apply(lazy[p],s[p*2+1]);
        lazy[p] = fe;
    }

    S query(int l,int r,int p,int L,int R){
        if(L<= l && R>=r) return s[p];
        else if(l>R || r<L) return se;
        else{
            int mid = (l+r)/2;
            push_down(p);
            return query(l,mid,p*2,L,R).merge(query(mid+1,r,p*2+1,L,R));
        }
    }

    void update(int l,int r,int p,int L,int R,int add,int mul){
        if(L<=l && R>=r){
            lazy[p] = lazy[p].composition({add,mul});
            s[p] = apply({add,mul},s[p]);
        }
        else if(l>R || r<L) return;
        else{
            int mid = (l+r)/2;
            push_down(p);
            update(l,mid,p*2,L,R,add,mul);
            update(mid+1,r,p*2+1,L,R,add,mul);
            s[p] = s[p*2].merge(s[p*2+1]);
        }
    }
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m>>p;
    for(int i = 1;i<=n;i++){
        cin>>da[i];
    }
    seg_tree st;
    st.build(1,n,1);
    int type,L,R,add,mul;
    for(int i = 1;i<=m;i++){
        cin>>type;
        if(type==1){
            cin>>L>>R>>mul;
            st.update(1,n,1,L,R,0,mul);
        }
        else if(type==2){
            cin>>L>>R>>add;
            st.update(1,n,1,L,R,add,1);
        }
        else{
            cin>>L>>R;
            cout<<st.query(1,n,1,L,R).val<<endl;
        }
    }
}