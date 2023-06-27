#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp(x,y) make_pair((x),(y))

ostream& operator<<(ostream& out,const vector<int>& arr){
    for(int i = 0;i<arr.size();i++){
        out<<arr[i]<<" ";
    }
    return out;
}
ostream& operator<<(ostream& out,const vector<bool>& arr){
    for(int i = 0;i<arr.size();i++){
        out<<arr[i]<<" ";
    }
    return out;
}
ostream& operator<<(ostream& out,const pair<int,int>& p){
    out<<p.first<<","<<p.second<<" ";
    return out;
}
ostream& operator<<(ostream& out,const map<pair<int,int>,int>& dic){
    for(auto iter = dic.begin();iter!=dic.end();iter++){
        out<<iter->first<<":"<<iter->second<<" ";
    }
    return out;
}

signed main(){
    int n;
    cin>>n;
    //handling the input.
    const int ARR_SIZE = n+1;
    vector adj(ARR_SIZE,vector<int>(0));
    map<pair<int,int>,int>weight;
    int u,v,w;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        weight[mp(u,v)] = w;
        weight[mp(v,u)] = w;
    }
    //Find a diameter point.
    vector<int>h(ARR_SIZE,0);
    vector<bool>vis(ARR_SIZE,false);
    auto clear_vis = [&]{
        for(int i = 0;i<vis.size();i++){
            vis[i] = false;
            h[i] = 0;
        }
    };
    auto clear_h = [&]{
        for(int i = 0;i<vis.size();i++){
            h[i] = 0;
        }
    };
    auto clear_vis_h = [&]{
        clear_vis();
        clear_h();
    };
    auto bfs_find = [&](vector<int>& h,int root){
        queue<int> q;
        q.push(root);
        vis[root] = true;
        while(q.size()>0){
            int qf = q.front();
            q.pop();
            for(int i = 0;i<adj[qf].size();i++){
                int now = adj[qf][i];
                if(vis[now]==false){
                    q.push(now);
                    vis[now] = true;
                    h[now] = h[qf] + weight[mp(qf,now)];
                }
            }
        }
        return max_element(h.begin(),h.end());
    };
    clear_vis_h();
    int da = bfs_find(h,1) - h.begin();
    clear_vis_h();
    int db = bfs_find(h,da) - h.begin();
    int d_len = h[db];
    //Find a diameter path.
    vector<int> diameter_path(0);
    for(int i = 0;i<vis.size();i++){
        vis[i] = false;
    }
    bool enable_path = false;
    function<void(int,int)> dfs_path = [&](int root,int now_weight){
        diameter_path.push_back(root);
        vis[root] = true;
        for(int i = 0;i<adj[root].size();i++){
            int now = adj[root][i];
            if(vis[now]==false){
                if(now_weight+ weight[mp(root,now)]==d_len && adj[now].size()==1){
                    diameter_path.push_back(now);
                    enable_path = true;
                    return;
                }
                dfs_path(now,now_weight+weight[mp(root,now)]);
                if(enable_path) return;
                diameter_path.pop_back();
            }
        }
    };
    dfs_path(da,0);
    int d_size = diameter_path.size();
    //Check connectivity.
    for(int i = 0;i<vis.size();i++){
        vis[i] = false;
    }
    for(int i =0;i<d_size;i++){
        vis[diameter_path[i]] = true;
    }
    int temp_h;
    vector<int> t_r(d_size,0);
    function<void(int,int)> dfs_check = [&](int root,int j){
        vis[root] = true;
        for(int i = 0;i<adj[root].size();i++){
            int now = adj[root][i];
            if(vis[now]==false){
                temp_h += weight[mp(root,now)];
                //Leaf Node;
                if(adj[now].size()==1){
                    t_r[j] = max(t_r[j],temp_h);
                }
                dfs_check(now,j);
                temp_h -= weight[mp(root,now)];
            }
        }
    };
    for(int i = 0;i<d_size;i++){
        temp_h = 0;
        dfs_check(diameter_path[i],i);
    }
    int fs = max_element(t_r.begin(),t_r.begin()+(d_size-1)/2+1) - t_r.begin();
    int ft = max_element(t_r.begin()+(d_size-1)/2+1,t_r.end()) - t_r.begin();
    int ans2 = abs(fs - ft);
    //Special Judge
    int accu_w = 0;
    for(int i = 1;i<d_size;i++){
        accu_w += weight[mp(diameter_path[i-1],diameter_path[i])];
        if(d_len - accu_w==accu_w){
            if(t_r[i]==accu_w) ans2 = 0;
            break;
        }
    }
    cout<<d_len<<endl;
    cout<<ans2<<endl;
}
/*
5
1 3 2
2 3 2
4 3 2 
5 3 2

9
1 2 1
2 5 3
3 4 2
4 5 1
5 6 1
6 7 3
5 8 2
8 9 2
*/