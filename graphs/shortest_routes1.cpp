#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"


vector<vector<pair<int,int>>>adj;

signed main() {
	int n,m;
	cin>>n>>m;
	adj.resize(n+1);
	for(int i=0;i<m;i++){
	    int a,b,c;
	    cin>>a>>b>>c;
	    adj[a].push_back({b,c});
	    
	}
	vector<int>vis(n+1,0);
	vector<int>dist(n+1,LLONG_MAX);
	dist[1]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,1});
	while(!pq.empty()){
	    auto top=pq.top();
	    pq.pop();
	    
	    int node=top.second;
	    if(vis[node])continue;
	    
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(dist[it.first]>dist[node]+it.second){
	            dist[it.first]=dist[node]+it.second;
	            pq.push({dist[it.first],it.first});
	        }
	    }
	    
	}
	for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
	cout<<endl;
	
}
