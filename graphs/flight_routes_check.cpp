#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

const int N=1e5+5;
int vis[N];
vector<int>adj[N][2];

void dfs(int node,int x){
    vis[node]=1;
    for(auto it:adj[node][x]){
        if(!vis[it])dfs(it,x);
    }
}
void solve(){
     int n,m;
     cin>>n>>m;
     
     for(int i=0;i<m;i++){
         int x,y;
         cin>>x>>y;
         adj[x][0].push_back(y);
         adj[y][1].push_back(x);
     }
     dfs(1,0);
     for(int i=1;i<=n;i++){
         if(!vis[i]){
             cout<<"NO"<<endl;
             cout<<1<<" "<<i<<endl;
             return ;
         }
     }
     memset(vis,0,sizeof(vis));
     dfs(1,1);
     for(int i=1;i<=n;i++){
         if(!vis[i]){
             cout<<"NO"<<endl;
             cout<<i<<" "<<1<<endl;
             return ;
         }
     }
     cout<<"YES"<<endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	
}
