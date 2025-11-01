#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"


const int N=2e5+5;
vector<int>adj[N];
int dp[N];
int ans[N];
int n;
void dfs(int node,int depth,int par=-1){
    ans[1]+=depth;
    dp[node]=1;
    for(auto it:adj[node]){
        if(it==par)continue;
        dfs(it,depth+1,node);
        dp[node]+=dp[it];
    }
}
void dfs2(int node,int par=-1){
    for(auto it:adj[node]){
        if(it==par)continue;
        ans[it]=(n-dp[it])-dp[it]+ans[node];
        dfs2(it,node);
    }
}
void solve(){
    
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    dfs2(1);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}
int32_t main() {
	
    solve();
}
