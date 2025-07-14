#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

int f(int a,int b,vector<vector<int>>&dp){
    if(a==b)return 0;
    if(a==1)return b-1;
    if(b==1)return a-1;
    if(dp[a][b]!=-1)return dp[a][b];
    int val=INT_MAX;
    for(int i=1;i<a;i++){
        val=min(val,f(i,b,dp)+f(a-i,b,dp)+1);
    }
    for(int j=1;j<b;j++){
        val=min(val,f(a,j,dp)+f(a,b-j,dp)+1);
    }
    return  dp[a][b]= val;
}
signed main() {
	int a,b;
	cin>>a>>b;
	vector<vector<int>>dp(a+1,vector<int>(b+1,INT_MAX));
	for(int i=0;i<=a;i++){
	    for(int j=0;j<=b;j++){
	        if(i==j)dp[i][j]=0;
	        else {
	            for(int k=1;k<i;k++){
	                dp[i][j]=min(dp[i][j],1+dp[i-k][j]+dp[k][j]);
	            }
	            for(int k=1;k<j;k++){
	                dp[i][j]=min(dp[i][j],1+dp[i][j-k]+dp[i][k]);
	            }
	        }
	    }
	}
	cout<<dp[a][b]<<endl;
}
