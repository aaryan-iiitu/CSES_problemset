#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"


const int mod=1e9+7;
const int N=1e5+5;
vector<pair<int,int>>adj[N];
signed main() {
	
	
	
	
    int n,m;
    cin>>n>>m;
    vector<int>dist(n+1,LLONG_MAX),ways(n+1,0),mx(n+1,0),mn(n+1,0);
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[1]=0;
    ways[1]=1;
    mx[1]=1;
    mn[1]=1;
    pq.push({0,1});
    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();
        int u=top.second;
        int d=top.first;
        if(dist[u]<d)continue;
        for(auto it:adj[u]){
            int v=it.first;
            int len=it.second;
            if(dist[v]>d+len){
                dist[v]=d+len;
                ways[v]=ways[u];
                mx[v]=mx[u]+1;
                mn[v]=mn[u]+1;
                pq.push({dist[v],v});
            }
            else if(dist[v]==(d+len)){
                ways[v]=(ways[v]+ways[u])%mod;
                mx[v]=max(mx[v],mx[u]+1);
                mn[v]=min(mn[v],mn[u]+1);
            }
        }
    }
    cout<<dist[n]<<" "<<ways[n]<<" "<<mn[n]-1<<" "<<mx[n]-1<<endl;
}
