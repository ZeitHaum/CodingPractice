#include <bits/stdc++.h>
using namespace std;
// #define DEBUG
#define int long long
inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct PSumer
{
    vector<vector<int>> P_Sum;
    PSumer(int N, vector<vector<char>>& P){
        P_Sum.resize(N + 1);
        for_each(P_Sum.begin(), P_Sum.end(), [&](auto& it){
            it.resize(N + 1);
            for_each(it.begin(), it.end(), [&](int& i){
                i = 0;
            });
        });
        for(int i = 1; i<=N; ++i){
            for(int j = 1; j<=N; ++j){
                P_Sum[i][j] = query(1, 1, i - 1, j) + query(1, 1, i, j - 1) + (int)(P[i][j] == 'B') - query(1, 1, i - 1, j - 1);
            }
        }
    }
    int query(int A, int B, int C, int D){
        if(C == 0 || D == 0) return 0;
        return P_Sum[C][D] - P_Sum[A - 1][D] - P_Sum[C][B - 1] + P_Sum[A - 1][B - 1];
    }
};

namespace math{
    inline int floor(int x, int d){
        return x / d;
    }
};

int N;
struct PArea
{
    int A;
    int B;
    int C;
    int D;
    int cnt;
    PSumer* ps;
    int id;
    PArea(int A_, int B_, int C_, int D_, int cnt_, PSumer* ps_, int id_)
    :A(A_), B(B_), C(C_), D(D_), cnt(cnt_), ps(ps_), id(id_){
        assert(A<=C);
        assert(B<=D);
        A = A % N;
        B = B % N;
        C = C % N;
        D = D % N;
    }
    int get_sum(){
        return ps->query(A+1, B+1, C+1, D+1) * cnt;
    }
};

struct PBigSumer{
    int N;
    PSumer* ps;
    vector<PArea>Ars;
    PBigSumer(int N_, PSumer* ps_)
    :N(N_), ps(ps_){
        Ars.reserve(4);
    }
    inline int get_big_sum(int A, int B){
        int h =  math::floor(A, N) * N;
        int v =  math::floor(B, N) * N;
        Ars.clear();
        //1
        if(h != 0 && v != 0){
            Ars.push_back({0, 0, N - 1, N - 1, (h/N) * (v/N), ps, 1});
        }
        //2
        if(h != 0){
            Ars.push_back({0, 0, N - 1, B, h/N, ps, 2});
        }
        //3
        if(v != 0){
            Ars.push_back({0, 0, A, N - 1, v/N,ps, 3});
        }
        //4
        Ars.push_back({0, 0, A, B, 1, ps, 4});
        int ans = 0;
        for(auto &ar:Ars){
            ans += ar.get_sum();
        }
        return ans;
    }
};

signed main(){
    #ifndef DEBUG
    fast_io();
    #endif
    int Q;
    cin >> N >> Q;
    vector<vector<char>> P(N + 1, vector<char>(N + 1));
    for(int i = 1; i<= N; ++i){
        for(int j =1; j<=N; ++j){
            cin >>P[i][j];
        }
    }
    int A, B, C, D;
    PSumer ps = PSumer(N, P);
    PBigSumer pbs = PBigSumer(N, &ps);
    for(int i = 1; i<=Q; ++i){
        cin >> A >> B >> C >> D;
        cout <<  pbs.get_big_sum(C, D) - (A == 0? 0 : pbs.get_big_sum(A - 1, D)) - (B == 0 ? 0 : pbs.get_big_sum(C, B - 1)) + (A == 0 || B == 0 ? 0 : pbs.get_big_sum(A - 1, B - 1)) << "\n";
    }
}
