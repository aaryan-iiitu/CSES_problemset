#include <bits/stdc++.h>
using namespace std;
#define int long long 


int solve(int n,vector<int>&a){
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)dp[i][i]=a[i];
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(j==i)continue;
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    int sum=accumulate(a.begin(),a.end(),0LL);
    return (dp[0][n-1]+sum)/2;
}
signed main() {
	int n;
    cin>>n;
    vector<int>a(n);
    for(int &x:a)cin>>x;
    cout<<solve(n,a)<<endl;
}
