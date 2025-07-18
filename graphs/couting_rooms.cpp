#include <bits/stdc++.h>
using namespace std;


int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void dfs(int i,int j,vector<string>&a,vector<vector<int>>&vis,int n,int m){
    vis[i][j]=1;
    for(int row=0;row<4;row++){
        int nrow=i+dx[row];
        int ncol=j+dy[row];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && a[nrow][ncol]=='.'){
            dfs(nrow,ncol,a,vis,n,m);
        }
    }
}
int main() {
	// your code goes here
    int n,m;
    cin>>n>>m;
    vector<string>a(n);
    for(string &x:a)cin>>x;
    vector<vector<int>>vis(n,vector<int>(m,0));
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!='.' || vis[i][j])continue;
            
            cnt++;
            dfs(i,j,a,vis,n,m);
            
        }
    }
    cout<<cnt<<endl;
}
