#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
#define int long long

struct S{
    int val;
    int len;
    S():val(0),len(0){}
    S(int val,int len):val(val),len(len){}
    S operator+(const S& s){
        return {this->val+s.val,this->len+s.len};
    }
};
int da[MAX_N];
S s[4*MAX_N];
const S se = {0,0};
int lazy[4*MAX_N];
struct seg_tree{
    //将lazy 标记向下传递
    void push_down(int p){
        lazy[p*2] += lazy[p];
        lazy[p*2+1] += lazy[p];
        s[p*2].val += lazy[p]*s[p*2].len;
        s[p*2+1].val += lazy[p]*s[p*2+1].len;
        lazy[p] = 0; 
    }
    //build
    void build(int l,int r,int p){
        if(l==r){
            s[p] = {da[l],1}; 
            return;
        }
        int mid = (l+r)/2;
        build(l,mid,p*2);
        build(mid+1,r,p*2+1);
        s[p] = s[p*2] + s[p*2+1];
    }
    //query
    S query(int l,int r,int p,int L,int R){
        if(L<=l && R>=r) return s[p];
        else if(l>R || r<L) return se;
        else{
            int mid = (l+r)/2;
            push_down(p);
            return query(l,mid,p*2,L,R) + query(mid+1,r,p*2+1,L,R);
        }
    }
    //update
    void update(int l ,int r,int p,int L,int R,int val){ 
        if(L<=l && R>=r) {
            lazy[p] += val;
            s[p].val += s[p].len*val;
        }
        else if(l>R || r<L) return;
        else{
            int mid = (l+r)/2;
            push_down(p);
            update(l,mid,p*2,L,R,val);
            update(mid+1,r,p*2+1,L,R,val);
            s[p] = s[p*2] + s[p*2+1];
        }
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    seg_tree st;
    for(int i = 1;i<=n;i++){
        cin>>da[i];
    }
    st.build(1,n,1);
    int type;
    int L,R,val;
    for(int i = 1;i<=m;i++){
        cin>>type;
        if(type==1){
            cin>>L>>R>>val;
            st.update(1,n,1,L,R,val);
        }
        else{
            cin>>L>>R;
            cout<<st.query(1,n,1,L,R).val<<endl;
        }
    }
}