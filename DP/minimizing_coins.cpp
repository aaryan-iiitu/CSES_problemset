#include <bits/stdc++.h>
using namespace std;
#define int long long 



void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int &y:a)cin>>y;
    sort(a.rbegin(),a.rend());
    vector<int>dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(a[j]<=i){
                dp[i]=min(dp[i],dp[i-a[j]]+1);
            }
        }
    }
    if(dp[x]>=INT_MAX){
        cout<<-1<<endl;
    }
    else cout<<dp[x]<<endl;
}
signed main() {
	// your code goes here
    solve();
}
