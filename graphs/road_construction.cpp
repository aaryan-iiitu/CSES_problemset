#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

const int N=1e5+5;
int par[N];
int sz[N];
map<int,int>mp;
int mx=0;
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
        mp.erase(y);
        mx=max(mx,sz[x]);
        
    }
    else {
        par[x]=y;
        sz[y]+=sz[x];
        mp.erase(x);
        mx=max(mx,sz[y]);
        
    }
}

void solve(){
     int n,m;
     cin>>n>>m;
     for(int i=1;i<=n;i++){
         par[i]=i;
         sz[i]=1;
         mp[i]++;
     }
     for(int i=0;i<m;i++){
         int x,y;
         cin>>x>>y;
         if(findpar(x)==findpar(y)){
             cout<<mp.size()<<" "<<mx<<endl;
             continue;
         }
         unite(x,y);
         cout<<mp.size()<<" "<<mx<<endl;
         
     }
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
