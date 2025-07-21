#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cnt=0;
    vector<int>par(n+1,-1);
    queue<int>q;
    q.push(1);
    vector<int>vis(n+1,0);
    vis[1]=1;
    while(!q.empty()){
        int sz=q.size();
        cnt++;
        while(sz--){
            int top=q.front();
            
            q.pop();
            if(top==n){
                cout<<cnt<<endl;
                vector<int>ans;
                int curr=n;
                while(curr!=-1){
                    ans.push_back(curr);
                    curr=par[curr];
                }
                reverse(ans.begin(),ans.end());
                for(auto it:ans)cout<<it<<" ";
                cout<<endl;
                return ;
            }
            for(auto it:adj[top]){
                if(!vis[it]){
                q.push(it);
                par[it]=top;
                vis[it]=1;
                }
            }
        }
        
    }
    cout<<"IMPOSSIBLE"<<endl;
}
signed main() {
	solve();
}
