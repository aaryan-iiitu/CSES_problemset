#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"


signed main() {
	int n,m;
	cin>>n>>m;
	vector<int>a(n),b(m);
	for(int &x:a)cin>>x;
	for(int &x:b)cin>>x;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;
    vector<int>ans;
    int i=n,j=m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else {
            int val1=dp[i-1][j];
            int val2=dp[i][j-1];
            if(val1==dp[i][j]){
                i--;
            }
            else j--;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans)cout<<it<<" ";
    cout<<endl;
}
