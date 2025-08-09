#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"


const int N=1e5+5;
vector<int>adj[N];
int child[N];
int vis[N];
int dp[N];


int dfs2(int node,int target){
    if(node==target)return dp[node]=1;
    if(dp[node]!=-1)return dp[node];
    int len=0;
    for(auto it:adj[node]){
        int temp=dfs2(it,target);
        int temp_len=temp==0?0:1+temp;
        if(temp_len>len){
            child[node]=it;
            len=temp_len;
        }
    }
    return dp[node]=len;
}

void dfs(int node){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it])dfs(it);
    }
}
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        
    }
    dfs(1);
    if(!vis[n]){
        cout<<"IMPOSSIBLE"<<endl;
        return ;
    }
    memset(dp,-1,sizeof(dp));
    int len=dfs2(1,n);
    vector<int>ans;
    int node=1;
    while(node){
        ans.push_back(node);
        node=child[node];
    }
    cout<<len<<endl;
    for(auto it:ans)cout<<it<<" ";
    cout<<endl;
}

signed main() {
    solve();
}
