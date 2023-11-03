#include <bits/stdc++.h>
using namespace std;

double calc_dis(int x1, int y1, int x2, int y2){
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void solve(){
    int px,py;
    cin>>px>>py;
    int ax, ay;
    cin>>ax>>ay;
    int bx, by;
    cin>>bx>>by;
    double ans_p = min(calc_dis(px, py, ax, ay), calc_dis(px, py, bx, by));
    double ans_o = min(calc_dis(ax, ay, 0, 0), calc_dis(bx, by, 0, 0));
    double ans2 = max({ans_p, ans_o, calc_dis(ax, ay, bx, by) / (double)2.0});
    double ans = min({ans2, max(calc_dis(px, py, ax, ay), calc_dis(ax, ay, 0, 0)), max(calc_dis(px, py, bx, by), calc_dis(bx,by,0,0))});
    printf("%.12f", ans);
    cout<<'\n';
}

signed main(){
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        solve();
    }
}