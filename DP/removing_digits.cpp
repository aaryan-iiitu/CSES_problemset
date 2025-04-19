#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;

int f(int n,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(n<0)return 1e6;
    if(dp[n]!=-1)return dp[n];
    string s=to_string(n);
    int ans=INT_MAX;
    for(int i=0;i<s.size();i++){
        int val=s[i]-'0';
        if(val==0)continue;
        int steps=1+f(n-val,dp);
        ans=min(ans,steps);
        
    }
    return dp[n]=ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    int ans=f(n,dp);
    cout<<ans<<endl;
}
signed main() {
	// your code goes here
    solve();
}
