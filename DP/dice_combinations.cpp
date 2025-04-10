#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1000000007;

int f(int n,vector<int>&dp){
    if(n<0)return 0;
    if(n==0)return 1;
    if(dp[n]!=-1)return dp[n];
    int cnt=0;
    for(int i=1;i<=6;i++){
        if((n-i)>=0){
             cnt=(cnt+(f(n-i,dp)%mod)%mod);
        }
    }
    return dp[n]=cnt%mod;
}
void solve(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<f(n,dp)<<endl;
}
signed main() {
	// your code goes here
    solve();
}
