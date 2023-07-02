#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001
#define int long long
#define LD pair<int,int>

int P[MAXN];
vector<LD>ld(MAXN);
priority_queue<int> pq;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	int N,M;
  	cin>>N>>M;
	for(int i = 1;i<=N;i++){
    	cin>>P[i];
      	pq.push(P[i]);
    }
  	for(int i = 1;i<=M;i++){
    	cin>>ld[i].first;
    }
  	for(int i = 1;i<=M;i++){
    	cin>>ld[i].second;
    }
  	sort(ld.begin()+1,ld.begin()+M+1);
  	reverse(ld.begin()+1, ld.begin()+M+1);
  	for(int i = 1;i<=M;i++){
    	int tp = pq.top();
      	pq.pop();
      	if(tp>=ld[i].first ){
        	tp = max(0ll, tp - ld[i].second);
        }
    }
  	int ans = 0;
  	while(!pq.empty()){
    	ans += pq.top();
      	pq.pop();
    }
  	cout<<ans<<"\n";
}