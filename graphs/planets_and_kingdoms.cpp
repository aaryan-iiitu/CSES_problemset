#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

const int N=1e5+5;

int vis[N];
vector<int>adj[N][2];
stack<int>st;
int label[N];
int curr=0;



void dfs(int node,int x){
    vis[node]=1;
    for(auto it:adj[node][x]){
        if(!vis[it])dfs(it,x);
    }
    st.push(node);
}
void dfs1(int node,int x){
    vis[node]=1;
    label[node]=curr;
    for(auto it:adj[node][x]){
        if(!vis[it])dfs1(it,x);
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
     for(int i=1;i<=n;i++){
         if(!vis[i]){
             dfs(i,0);
         }
     }
     memset(vis,0,sizeof(vis));
     while(!st.empty()){
         int top=st.top();
         st.pop();
         if(vis[top])continue;
         curr++;
         dfs1(top,1);
     }
     cout<<curr<<endl;
     for(int i=1;i<=n;i++){
         cout<<label[i]<<" ";
     }
     cout<<endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	
}
