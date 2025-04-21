#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;

void solve(){
   int n,m;
   cin>>n>>m;
   vector<int>a(n);
   for(int &x:a){
       cin>>x;
   }
   vector<vector<int>>dp(n+1,vector<int>(m+1,0));
   if(a[0]==0){
       for(int j=0;j<=m;j++){
           dp[0][j]=1;
       }
   }
   else {
       dp[0][a[0]]=1;
   }
   for(int i=1;i<n;i++){
       if(a[i]==0){
           for(int j=1;j<=m;j++){
               dp[i][j]=dp[i-1][j];
               if(j-1>=1)dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
               if(j+1<=m)dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;;
           }
       }
       else {
           dp[i][a[i]]=dp[i-1][a[i]];
           if(a[i]-1>=1)dp[i][a[i]]=(dp[i][a[i]]+dp[i-1][a[i]-1])%mod;
           if(a[i]+1<=m)dp[i][a[i]]=(dp[i][a[i]]+dp[i-1][a[i]+1])%mod;
       }
   }
   int ans=0;
   for(int i=1;i<=m;i++){
       ans=(ans+dp[n-1][i])%mod;
   }
   cout<<ans<<endl;
}
signed main() {
	  solve();
}
