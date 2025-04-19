#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;

int f(vector<string>&a,int n,int i,int j,vector<vector<int>>&dp){
    if(i==(n-1) && j==(n-1))return 1;
    if(i<0 || i>=n || j<0 || j>=n || a[i][j]=='*')return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int right=0,down=0;
    right=f(a,n,i+1,j,dp);
    down=f(a,n,i,j+1,dp);
    return  dp[i][j]= (right+down)%mod;
}
void solve(){
    int n;
    cin>>n;
    vector<string>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(a[0][0]=='*' || a[n-1][n-1]=='*'){
        cout<<0<<endl;
        return;
    }
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int ans=f(a,n,0,0,dp);
    cout<<ans<<endl;
}
signed main() {
	// your code goes here
    solve();
}
