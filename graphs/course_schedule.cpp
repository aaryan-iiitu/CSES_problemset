#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N=1e5+5;
vector<int>adj[N];
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>indeg(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)q.push(i);
    }
    vector<int>ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            indeg[it]--;
            if(indeg[it]==0)q.push(it);
        }
    }
    if(ans.size()<n){
        cout<<"IMPOSSIBLE"<<endl;
        return ;
    }
    for(auto it:ans)cout<<it<<" ";
    cout<<endl;
}

signed main() {
    solve();
}
