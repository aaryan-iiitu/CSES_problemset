#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 1e5 + 5;
vector<int> adj[N];
int par[N], state[N], x = -1;

bool dfs(int node) {
    state[node]=1;
    for(auto it:adj[node]){
        if(state[it]==0 ){
            par[it]=node;
            if(dfs(it))return true;
            
        }
        else if(state[it]==1 ){
            par[it]=node;
            x=it;
            return true;
        }
    }
    state[node]=2;
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(par, -1, sizeof(par));
    for(int i=1;i<=n;i++){
        if(state[i]==0 && dfs(i)){
            vector<int>ans;
            int v=par[x];
            ans.push_back(x);
            while(v!=x){
                ans.push_back(v);
                v=par[v];
            }
            ans.push_back(x);
            
            reverse(ans.begin(),ans.end());
            cout<<ans.size()<<endl;
            for(auto it:ans)cout<<it<<" ";
            cout<<endl;
            return ;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}

signed main() {
    solve();
}
