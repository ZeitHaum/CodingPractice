#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 30'0001

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int a[MAXN];
int d[MAXN];

struct Monster
{
    int a;
    int d;
    int h;
};

struct Interval
{
    bool valid;
    list<Monster>::iterator begin;
    list<Monster>::iterator end;
};

#define calc_h(x) x->h = 0;\
    if(x!=mons.begin()){ \
        x->h += prev(x)->a;\
    }\
    if(next(x)!=mons.end()){\
        x->h += next(x)->a;\
    }


list<Monster> mons;

void solve(){
    int n;
    cin >> n;
    mons.clear();
    for(int i = 1; i<=n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i<=n; ++i){
        cin >> d[i];
        mons.insert(mons.end(),{a[i], d[i], 0});
    }
    if(n == 1){
        cout << "0\n";
        return ;
    }
    vector<Interval> dies[2];
    vector<list<Monster>::iterator> changed_iters;
    //die2 is tmp;
    dies[0].reserve(n);
    dies[1].reserve(n);
    changed_iters.reserve(n);
    int now_die = 0;
    // n rounds
    int ans = 0;
    for(int i = 1; i<=n; ++i){
        ans = 0;
        changed_iters.clear();
        if(i == 1){
            // hurts;
            for(auto x = mons.begin(); x!=mons.end(); ++x){
                calc_h(x);
            }
            //decide now_die
            Interval now_intv;
            now_intv.valid = false;
            for(auto x = mons.begin(); x!=mons.end(); ++x){
                if(x->h > x->d){
                    ++ans;
                    if(now_intv.valid) now_intv.end = x;
                    else now_intv.begin = x, now_intv.end = x, now_intv.valid = true;
                }
                else{
                    if(now_intv.valid) {
                        now_intv.valid = false;
                        dies[now_die].push_back(now_intv);
                    }
                }
            }
            if(now_intv.valid){
                dies[now_die].push_back(now_intv);
            }
            cout << ans;
            now_die^=1;
            dies[now_die].clear();
        }
        else{
            //hurts and erase
            for(auto& intv : dies[now_die ^ 1]){
                list<Monster>::iterator rtmp;
                rtmp = mons.erase(intv.begin, next(intv.end));
                if(rtmp!=mons.begin() && !mons.empty()) {
                    calc_h(prev(rtmp));
                    if(changed_iters.back()!=prev(rtmp)) changed_iters.push_back(prev(rtmp));
                }
                if(rtmp!=mons.end()) {
                    calc_h(rtmp);
                    changed_iters.push_back(rtmp);
                }
            }
            //calc now_die
            Interval now_intv;
            now_intv.valid = false;
            for(auto x : changed_iters){
                if(x->h > x->d){
                    ans++;
                    if(!now_intv.valid){
                        now_intv.begin = x;
                        now_intv.end = x;
                        now_intv.valid = true;
                    }
                    else{
                        if(x != mons.begin() && prev(x) == now_intv.end){
                            now_intv.end = x;
                        }
                        else{
                            dies[now_die].push_back(now_intv);
                            now_intv.begin = x;
                            now_intv.end = x;
                        }
                    }
                }
                else{
                    if(now_intv.valid) {
                        dies[now_die].push_back(now_intv);
                        now_intv.valid = false;
                    }
                }
            }
            if(now_intv.valid){
                dies[now_die].push_back(now_intv);
            }
            // trans_nowdie ans last_die
            now_die ^=1;
            dies[now_die].clear();
            cout << " " << ans;
        }
    }
    cout << "\n";
}

signed main(){
    fast_io();
    int t;
    cin >> t;
    for(int i = 0; i<t; ++i){
        solve();
    }
}
/*
*/