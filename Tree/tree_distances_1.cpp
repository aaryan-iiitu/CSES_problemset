#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"


const int N=2e5+5;
vector<int>adj[N];
int dist[N];
int node1,node2;
int curr;
int mx=-1;



void dfs(int node,int par=-1){
    for(auto it:adj[node]){
        if(it==par)continue;
        dist[it]=max(dist[it],1+dist[node]);
        if(dist[it]>mx){
            mx=dist[it];
            curr=it;
        }
        dfs(it,node);
    }
}
void dfs2(int node,vector<int>&dp,int par=-1){
    for(auto it:adj[node]){
        if(it==par)continue;
        dp[it]=max(dp[it],1+dp[node]);
        dfs2(it,dp,node);
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    node1=curr;
    mx=-1;
    for(int i=1;i<=n;i++)dist[i]=0;
    dfs(node1);
    node2=curr;
    vector<int>dp1(n+1,0),dp2(n+1,0);
    dfs2(node1,dp1);
    dfs2(node2,dp2);
    for(int i=1;i<=n;i++)cout<<max(dp1[i],dp2[i])<<" ";
    cout<<endl;
}
int32_t main() {
	
    solve();
}
