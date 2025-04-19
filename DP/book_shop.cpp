#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int> page(n),price(n);
    for(int &y:price){
        cin>>y;
    }
    for(int &y:page){
        cin>>y;
    }
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j]=dp[i-1][j];
            if(price[i-1]<=j){
                dp[i][j]=max(dp[i][j],dp[i-1][j-price[i-1]]+page[i-1]);
            }
        }
    }
    cout<<dp[n][x]<<endl;
}
