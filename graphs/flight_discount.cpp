#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N=1e5+5;
int vis[N];
int dist1[N],dist2[N];

void dfs(int node,vector<pair<int,int>>adj[],int dist[]){
    priority_queue<pair<int,int>>pq;
    pq.push({0,node});
    for(int i=1;i<=1e5;i++)dist[i]=1e17,vis[i]=0;
    dist[node]=0;
    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();
        int curr=top.second;
        if(vis[curr])continue;
        vis[curr]=1;
        for(auto [b,w]:adj[curr]){
            if(dist[curr]+w<dist[b]){
                dist[b]=dist[curr]+w;
                pq.push({-dist[b],b});
            }
        }
    }
}
void solve(){
   int n,m;
   cin>>n>>m;
   vector<tuple<int,int,int>>edges;
   vector<pair<int,int>>adj1[n+1],adj2[n+1];
   for(int i=0;i<m;i++){
       int x,y,z;
       cin>>x>>y>>z;
       adj1[x].push_back({y,z});
       adj2[y].push_back({x,z});
       edges.push_back({x,y,z});
   }
   dfs(1,adj1,dist1);
   dfs(n,adj2,dist2);
   int mn=1e17;
   for(auto [x,y,z]:edges){
       mn=min(mn,dist1[x]+dist2[y]+z/2);
   }
   cout<<mn<<endl;
    
}    
signed main(){
    solve();
}