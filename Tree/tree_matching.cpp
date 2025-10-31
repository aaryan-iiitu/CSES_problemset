#include <bits/stdc++.h>
#include <iostream>
#include <utility>
 
using namespace std;
const int mod=1000000007;
 
vector<vector<int>> dp;
int tree(int node,int p,vector<vector<int>> &adj,int take){
    int ans=0;
    if(dp[node][take]!=-1) return dp[node][take];
    if(take){ //allowed to take
        for(auto i:adj[node]){
            if(i==p) continue;
            ans+=max(tree(i,node,adj,1),tree(i,node,adj,0));
        }
        int temp=0;
        for(auto i:adj[node]){
            if(i==p) continue;
            temp=max(temp,ans+1-max(tree(i,node,adj,1),tree(i,node,adj,0))+tree(i,node,adj,0));
        }
        return dp[node][take]=temp;
    }
    else{
        for(auto i:adj[node]){
            if(i==p) continue;
            ans+=max(tree(i,node,adj,1),tree(i,node,adj,0));
        }
        return dp[node][take]=ans;
    }
 
}
void solve() {
    int n;
    cin>>n;
    dp.resize(n+1,vector<int>(2,-1));
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u;
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<max(tree(1,0,adj,1),tree(1,0,adj,0))<<endl;
 
}
 
int main(){ 
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    while(t--) {
        solve();
    }
    return 0; 
}