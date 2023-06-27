#include <bits/stdc++.h>
using namespace std;
 
ostream& operator<<(ostream& out, vector<int>& arr){
    for(int i = 0;i<arr.size();i++){
        out<<arr[i]<<" "; 
    }
    return out;
}
 
int main(){
    int n;
    cin>>n;
    vector adj(n+1,vector<int>(0));
    int u,v;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector dis_1(n+1,-1);
    vector dis_2(n+1,-1);
    auto bfs = [&](vector<int>& height,int root){
        queue<int> q;
        q.push(root);
        height[root] = 0;
        vector<bool>vis(n+1,false);
        while(q.size()!=0){
            int qf = q.front();
            q.pop();
            vis[qf] = true;
            for(int i  = 0;i<adj[qf].size();i++){
                int now = adj[qf][i];
                if(!vis[now]){
                    q.push(now);
                    height[now] = height[qf]+1;
                    vis[now] = true;
                }
            }
        }
    };
    bfs(dis_2,1);
    int max_root = max_element(dis_2.begin(),dis_2.end()) - dis_2.begin();
    bfs(dis_1,max_root);
    max_root = max_element(dis_1.begin(),dis_1.end()) - dis_1.begin();
    bfs(dis_2,max_root);
    for(int i = 0;i<dis_1.size();i++){
        dis_1[i] = max(dis_1[i],dis_2[i]);
    }
    sort(dis_1.begin(),dis_1.end());
    vector ans(n+1,0);
    for(int i =1;i<dis_1.size();i++){
        ans[dis_1[i]]++;
    }
    cerr<<ans<<endl;
    ans[n] = n;
    bool enable = false;
    for(int i = ans.size()-2;i>=0;i--){
        int temp = 0;
        if(ans[i]!=0 && !enable){
            temp = 1;
            enable = true;
        }
        ans[i] = ans[i+1] - ans[i] + temp;
    }
    for(int i = 1;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}