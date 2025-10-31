#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
 
const int N=2e5+5;
vector<int>adj[N];
int dist[N];
int mx=0;
int node=-1;
void dfs(int val,int par=-1){
    for(auto it:adj[val]){
        if(it==par)continue;
        
        dist[it]=max(dist[it],1+dist[val]);
        if(mx<dist[it]){
            node=it;
            mx=dist[it];
        }
        dfs(it,val);
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
   for(int i=1;i<=n;i++)dist[i]=0;
   mx=0;
   dfs(node);
   int ans=0;
   for(int i=1;i<=n;i++){
       ans=max(ans,dist[i]);
   }
   cout<<ans<<endl;
}
signed main() {
	solve();
}