#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

vector<vector<int>>adj;
bool fl=false;
vector<int>ans;
vector<int>vis;
vector<int>parent;
int sv,ev;
int n,m;
bool dfs(int node,int par){
    vis[node]=1;
    parent[node]=par;
    for(auto adjnode:adj[node]){
        if(adjnode==par)continue;
        if(vis[adjnode]){
            sv=adjnode;
            ev=node;
            return true;
        }
        if(!vis[adjnode]){
            if(dfs(adjnode,node))return true;
        }
    }
    return false;
}
bool f(){
    for(int i=1;i<=n;i++){
        if(!vis[i])if(dfs(i,-1))return true;
    }
    return false;
}


signed main() {
	// your code goes here
    
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    parent.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(!f()){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    int tv=ev;
    ans.push_back(ev);
    while(tv!=sv){
        ans.push_back(parent[tv]);
        tv=parent[tv];
    }
    ans.push_back(ev);
    cout<<ans.size()<<endl;
    for(auto it:ans)cout<<it<<" ";
    cout<<endl;
}
