#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

int f(int ind1,int ind2,string &a,string &b,int n,int m,vector<vector<int>>&dp){
    if(ind1>=n && ind2>=m)return 0;
    if(ind1>=n && ind2<=m-1)return m-ind2;
    else if(ind2>=m && ind1<=n-1)return n-ind1;
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    int first=INT_MAX,second=INT_MAX,third=INT_MAX;
    if(a[ind1]==b[ind2])first=f(ind1+1,ind2+1,a,b,n,m,dp);
    second=1+min(f(ind1+1,ind2,a,b,n,m,dp),f(ind1,ind2+1,a,b,n,m,dp));
    third=1+f(ind1+1,ind2+1,a,b,n,m,dp);
    return  dp[ind1][ind2]= min({first,second,third});
}
signed main() {
	// your code goes here
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][m]=n-i;
    }
    for(int i=0;i<=m;i++){
        dp[n][i]=m-i;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(a[i]==b[j])dp[i][j]=dp[i+1][j+1];
            else {
                int ops1=dp[i+1][j+1]+1;
                int ops2=1+min(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=min(ops1,ops2);
            }
        }
    }
    cout<<dp[0][0]<<endl;
}
