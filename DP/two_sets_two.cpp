#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int mod=1e9+7;
void f(){
    int n;
    cin>>n;
    if((n*(n+1)/2)&1){
        cout<<0<<endl;
        return ;
    }
    int s=n*(n+1)/4;
    vector<vector<int>>dp(n+1,vector<int>(s+1,0));
    for(int i=1;i<=n;i++)dp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int val=1;val<=s;val++){
            dp[i][val]=(dp[i-1][val])%mod;
            if(val-i>=0)dp[i][val]=(dp[i][val]+dp[i-1][val-i])%mod;
        }
    }
    cout<<dp[n][s]<<endl;
}
signed main() {
	f();
}
