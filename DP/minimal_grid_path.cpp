#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"


signed main() {
	int n;
	cin>>n;
	vector<string>a(n);
	for(string &x:a)cin>>x;
	vector<vector<string>>dp(n,vector<string>(n));
	dp[0][0]=string(1,a[0][0]);
	for(int i=1;i<n;i++)
	dp[0][i]=dp[0][i-1]+a[0][i];
	
	for(int i=1;i<n;i++)
	dp[i][0]=dp[i-1][0]+a[i][0];
	
	for(int i=1;i<n;i++){
	    for(int j=1;j<n;j++){
	        string up=dp[i-1][j]+a[i][j];
	        string left=dp[i][j-1]+a[i][j];
	        dp[i][j]=min(up,left);
	    }
	}
	
	
	cout<<dp[n-1][n-1]<<endl;
}
