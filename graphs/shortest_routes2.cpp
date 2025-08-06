#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
 
 
signed main() {
	// your code goes here
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>>dist(n+1,vector<int>(n+1,LLONG_MAX));
    for(int i=1;i<=n;i++)dist[i][i]=0;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        if(x!=y)
        dist[x][y]=dist[y][x]=min(dist[x][y],z);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dist[j][i]<LLONG_MAX && dist[i][k]<LLONG_MAX)
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(dist[a][b]!=LLONG_MAX)
        cout<<dist[a][b]<<endl;
        else cout<<-1<<endl;
    }
}
