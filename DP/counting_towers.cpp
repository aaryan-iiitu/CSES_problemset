#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
vector<vector<int> >dp;
void solve(){
  int n;
  cin>>n;
  dp[n][0]=1;
  dp[n][1]=1;
  for(int i=n-1;i>=0;i--){
      dp[i][0]=(2LL*dp[i+1][0]+dp[i+1][1])%mod;
      dp[i][1]=(4LL*dp[i+1][1]+dp[i+1][0])%mod;
  }
  cout<<(dp[1][0]+dp[1][1])%mod<<endl;
}
signed main() {
      int t;
      cin>>t;
      dp = vector<vector<int> >(1e6+1,vector<int>(2,0));
      while(t--){
	  solve();
      }
}
