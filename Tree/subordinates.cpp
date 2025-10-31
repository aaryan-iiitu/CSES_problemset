#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
 
const int N=2e5+5;
int sz[N];
void dfs(vector<vector<int>>&adj,int node,int par=-1){
    sz[node]=1;
    for(auto it:adj[node]){
        if(it!=par){
            dfs(adj,it,node);
            sz[node]+=sz[it];
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        adj[x].push_back(i+2);
        adj[i+2].push_back(x);
    }
    dfs(adj,1);
    for(int i=1;i<=n;i++){
        cout<<sz[i]-1<<" ";
    }
    cout<<endl;
    
}
signed main() {
	solve();
}