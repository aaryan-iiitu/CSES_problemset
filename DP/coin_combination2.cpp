#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int &y:a)cin>>y;
    vector<int>dp(x+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            if(j>=a[i])dp[j]=(dp[j]+dp[j-a[i]])%mod;
        }
    }
    cout<<dp[x]<<endl;
}
signed main() {
	// your code goes here
    solve();
}
