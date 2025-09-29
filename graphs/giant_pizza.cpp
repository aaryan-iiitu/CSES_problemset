#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=200020;

vector<int>adj[N];
vector<int>adjt[N];
vector<int>topo;
int colors[N];
bool vis[N];


void dfs(int node){
    vis[node]=true;
    for(int child:adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
    topo.push_back(node);
}

void dfs2(int node,int color){
    vis[node]=true;
    colors[node]=color;
    for(auto child:adjt[node]){
        if(!vis[child]){
            dfs2(child,color);
        }
    }
}
signed main() {
	// your code goes here
    int n,m;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        char c1,c2;
        int x1,x2;
        
        cin>>c1>>x1>>c2>>x2;
        int b1=(c1=='+')?1:0;
        int b2=(c2=='+')?1:0;
        x1--;
        x2--;
        adj[n*(1-b1)+x1].push_back(n*b2 +x2);
        adjt[n*b2+x2].push_back(n*(1-b1)+x1);
        adj[n*(1-b2)+x2].push_back(n*b1+x1);
        adjt[n*b1+x1].push_back(n*(1-b2)+x2);
    }
    memset(vis,false,sizeof(vis));
    for(int i=0;i<2*n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    memset(vis,false,sizeof(vis));
    reverse(topo.begin(),topo.end());
    int color=0;
    for(int node:topo){
        if(!vis[node]){
            dfs2(node,color++);
        }
    }
    vector<char>ans(n);
    for(int i=0;i<n;i++){
        if(colors[i]==colors[i+n]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
         if(colors[i]<colors[i+n]){
            ans[i]='+';
        }
        if(colors[i]>colors[i+n]){
            ans[i]='-';
        }
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}
