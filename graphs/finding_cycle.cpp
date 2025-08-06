#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
 
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edges.push_back({x,y,z});
    }
    vector<int>dist(n+1,0);
    vector<int>par(n+1,-1);
    int x;
    for(int i=0;i<n;i++){
        x=-1;
        for(auto it:edges){
            if(dist[it[0]]+it[2]<dist[it[1]]){
                x=it[1];
                dist[it[1]]=dist[it[0]]+it[2];
                par[it[1]]=it[0];
            }
        }
    }
    if(x==-1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    vector<int>cycle;
    for(int i=0;i<n;i++)x=par[x];
    for(int v=x;;v=par[v]){
        cycle.push_back(v);
        if(v==x && cycle.size()>1)break;
    }
    reverse(cycle.begin(),cycle.end());
    for(auto it:cycle)cout<<it<<" ";
    cout<<endl;
}
signed main() {
	// your code goes here
    solve();
}
