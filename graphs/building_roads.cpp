#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int vis[100001];
void dfs(int node,vector<vector<int>>&adj){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj);
        }
    }
}
int main() {
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n+1);
	for(int i=0;i<m;i++){
	    int x,y;
	    cin>>x>>y;
	    adj[x].push_back(y);
	    adj[y].push_back(x);
	}
	int cnt=0,prev=-1;
	vector<pair<int,int>>ans;
	for(int i=1;i<=n;i++){
	    
	    if(vis[i])continue;
	    cnt++;
	    if(prev!=-1){
	        ans.push_back({prev,i});
	       
	    }
	    prev=i;
	    dfs(i,adj);
	}
	cout<<cnt-1<<endl;
	for(auto it:ans){
	    cout<<it.first<<" "<<it.second<<endl;
	}
}
