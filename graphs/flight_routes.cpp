#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

const int N=2e5+5;
priority_queue<int>best[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<pair<int,int>>adj[N];
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
    }
    best[1].push(0);
    pq.push({0,1});
    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();
        if(top.first>best[top.second].top())continue;
        for(auto adjnode:adj[top.second]){
            int temp=top.first+adjnode.second;
            if(best[adjnode.first].size()<k){
                best[adjnode.first].push(temp);
                pq.push({temp,adjnode.first});
            }
            else if(temp<best[adjnode.first].top()){
                best[adjnode.first].pop();
                best[adjnode.first].push(temp);
                pq.push({temp,adjnode.first});
            }
        }
    }
    vector<int>ans;
    while(!best[n].empty()){
        ans.push_back(best[n].top());
        best[n].pop();
        
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans)cout<<it<<" ";
    cout<<endl;
}
signed main() {
	// your code goes here
    solve();
}
