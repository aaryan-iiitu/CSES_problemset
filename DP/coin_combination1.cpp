#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1000000007;

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int &y:a)cin>>y;
    vector<int>dp(x+1,0);
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int coin:a){
            if(i-coin>=0)dp[i]=(dp[i]+dp[i-coin])%mod;
        }
    }
    cout<<dp[x]<<endl;
}
signed main() {
	// your code goes here
    solve();
}
