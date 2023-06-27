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
    auto bfs_find = [&](vector<int>& h,int root){
        queue<int> q;
        q.push(root);
        for(int i = 0;i<vis.size();i++){
            vis[i] = false;
            h[i] = 0;
        }
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
    int da = bfs_find(h,1) - h.begin();
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
    vector<bool> a_multi(d_size,false);
    vector<bool> b_multi(d_size,false);
    int ans = 0;
    int wa_ck = 0;
    int wb_ck = d_len;
    function<void(int,int)> dfs_check = [&](int root,int j){
        vis[root] = true;
        for(int i = 0;i<adj[root].size();i++){
            int now = adj[root][i];
            if(vis[now]==false){
                temp_h += weight[mp(root,now)];
                //Leaf Node;
                if(adj[now].size()==1){
                    if(temp_h==wb_ck){
                        if(wa_ck==wb_ck && a_multi[j]==false) continue;
                        b_multi[j] = true;
                    }
                    if(temp_h==wa_ck){a_multi[j] = true;}
                }
                dfs_check(now,j);
                temp_h -= weight[mp(root,now)];
            }
        }
    };
    for(int i = 0;i<d_size;i++){
        temp_h = 0;
        if(i>0){
            wb_ck-= weight[mp(diameter_path[i],diameter_path[i-1])];
            wa_ck+= weight[mp(diameter_path[i],diameter_path[i-1])];
        }
        dfs_check(diameter_path[i],i);
    }
    int a_forward = 0;
    int b_backward = d_size-1;
    for(int i = 0;i<d_size;i++){
        if(a_multi[i]) a_forward = i;
    }
    for(int i = d_size-1;i>=0;i--){
        if(b_multi[i]) b_backward = i;
    }
    cout<<d_len<<endl;
    if(a_forward>= b_backward) cout<<0<<endl;
    else cout<<b_backward - a_forward<<endl;
}