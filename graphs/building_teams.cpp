#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

const int maxn=100002;
int color[maxn];
bool fl=false;
void dfs(int node,vector<int>&vis,vector<vector<int>>&adj){
    vis[node]=1;
    for(auto it:adj[node]){
        if( color[it]==color[node]){
                fl=true;
                return ;
            }
        if(!vis[it]){
            color[it]=3-color[node];
            dfs(it,vis,adj);
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>vis(n+1,0);
    memset(color,-1,sizeof(color));
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            
            color[i]=1;
            dfs(i,vis,adj);
        }
    }
    if(fl){
        cout<<"IMPOSSIBLE"<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        cout<<color[i]<<" ";
    }
    cout<<endl;
}
signed main() {
	solve();
}
