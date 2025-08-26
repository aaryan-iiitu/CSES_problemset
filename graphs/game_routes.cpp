#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

const int N=1e5+5;
int vis[N];
vector<int>adj[N];
int dp[N];
const int mod=1e9+7;
int n,m;

int dfs(int node ){
    vis[node]=1;
    if(node==n){
        vis[node]=2;
        dp[node]=1;
        return 0;
    }
    for(auto it:adj[node]){
        
        if(vis[it]==0){
            dfs(it);
        }
        dp[node]+=dp[it];
        dp[node]=dp[node]%mod;
    }
    vis[node]=2;
    return dp[node];
}
signed main() {
	// your code goes here
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    int ans=dfs(1);
    cout<<ans<<endl;
    
}
