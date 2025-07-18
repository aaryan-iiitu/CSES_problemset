#include <bits/stdc++.h>
using namespace std;

int n,m;
char arr[1001][1001];
bool vis[1001][1001];
char b[1001][1001];
vector<char>path;


bool isvalid(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==false && arr[x][y]!='#')return true;
    return false;
}
bool bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=true;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int row=it.first;
        int col=it.second;
        if(arr[row][col]=='B'){
            while(1){
                path.push_back(b[row][col]);
                if(path.back()=='U')row++;
                else if(path.back()=='D')row--;
                else if(path.back()=='L')col++;
                else col--;
                if(row==x && col==y){
                    break;
                }
            }
            return true;
        }
        if(isvalid(row+1,col))b[row+1][col]='D',q.push({row+1,col}),vis[row+1][col]=1;
        if(isvalid(row-1,col))b[row-1][col]='U',q.push({row-1,col}),vis[row-1][col]=1;
        if(isvalid(row,col+1))b[row][col+1]='R',q.push({row,col+1}),vis[row][col+1]=1;
        if(isvalid(row,col-1))b[row][col-1]='L',q.push({row,col-1}),vis[row][col-1]=1;
        
    }
    return false;
}
int main() {
	// your code goes here
    cin>>n>>m;
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='A'){
                x=i;
                y=j;
            }
        }
    }
    if(bfs(x,y)){
        cout<<"YES"<<endl;
        cout<<path.size()<<endl;
        while(path.size()>0)cout<<path.back(),path.pop_back();
        cout<<endl;
    }
    else cout<<"NO"<<endl;
}
