#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 

const int N=2e5+5;
int vis[N];
vector<int>adj[N];
vector<int>adjt[N];
int cost[N];
stack<int>topo;
int comp[N],compcost[N];
vector<int>dag[N];
int dp[N];
int mx=0;
int indeg[N];
int compcount=0;


void dfs(int node){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it])
        dfs(it);
    }
    topo.push(node);
}

void dfs2(int node,int cid){
    
    vis[node]=1;
    
    comp[node]=cid;
    compcost[cid]+=cost[node];
    for(auto it:adjt[node]){
        if(!vis[it])dfs2(it,cid);
    }

}
signed main() {
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>cost[i];
	}
	for(int i=0;i<m;i++){
	    int x,y;
	    cin>>x>>y;
	    adj[x].push_back(y);
	    adjt[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
	    if(!vis[i]){
	        dfs(i);
	    }
	}
	
	memset(vis,0,sizeof(vis));
	while(!topo.empty()){
	    int i=topo.top();
	    topo.pop();
	    if(!vis[i]){
	        ++compcount;
	        dfs2(i,compcount);
	        
	    }
	}
	// building the SCC-DAG
	
	for(int i=1;i<=n;i++){
	    for(auto v:adj[i]){
	        if(comp[i]!=comp[v]){
	            dag[comp[i]].push_back(comp[v]);
	            indeg[comp[v]]++;
	        }
	    }
	}
	
	// doing topo sort and building the dp  array 
	queue<int>q;
	for(int i=1;i<=compcount;i++){
	    dp[i]=compcost[i];
	    if(indeg[i]==0)q.push(i);
	}
	int ans=0;
	while(!q.empty()){
	    int u=q.front();
	    q.pop();
	    ans=max(ans,dp[u]);
	    for(auto v:dag[u]){
	        dp[v]=max(dp[v],dp[u]+compcost[v]);
	        indeg[v]--;
	        if(indeg[v]==0){
	            q.push(v);
	        }
	    }
	}
	cout<<ans<<endl;
}
