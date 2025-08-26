#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

const int N=2e5+5;
int par[N];
int sz[N];

int findpar(int u){
    if(u==par[u])return u;
    return par[u]=findpar(par[u]);
}
void unite(int x,int y){
    x=findpar(x),y=findpar(y);
    if(x==y)return ;
    if(sz[x]>sz[y]){
        par[y]=x;
        sz[x]+=sz[y];
    }
    else {
        par[x]=y;
        sz[y]+=sz[x];
    }
}

void solve(){
   int n,m;
   cin>>n>>m;
   vector<vector<int>>adj;
   for(int i=0;i<m;i++){
       int x,y,z;
       cin>>x>>y>>z;
       adj.push_back({z,x,y});
   }
   sort(adj.begin(),adj.end());
   for(int i=1;i<=n;i++){
       par[i]=i;
       sz[i]=1;
   }
   int ans=0;
   for(auto it:adj){
       if(findpar(it[1])==findpar(it[2]))continue;
       unite(it[1],it[2]);
       ans+=it[0];
   }
   bool fl=false;
   for(int i=1;i<=n;i++){
       if(findpar(i)==i){
           if(fl){
               cout<<"IMPOSSIBLE"<<endl;
               return ;
           }
           fl=true;
       }
   }
   cout<<ans<<endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	//int t;
	//cin>>t;
	//while(t--){
	    solve();
	//}
    
}
