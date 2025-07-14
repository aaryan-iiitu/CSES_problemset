#include <bits/stdc++.h>
using namespace std;
#define int long long 


string solve(int n,vector<string>&a){
    vector<vector<string>>dp(n,vector<string>(n,""));
    dp[0][0]=a[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j && i==0)continue;
            string up=i>0?dp[i-1][j]:"";
            
            string left=j>0?dp[i][j-1]:"";
            if(up.size()==0 && left.size()==0)continue;
            if(up.size()==0){
                dp[i][j]=dp[i][j-1]+a[i][j];
            }
            else if(left.size()==0){
                dp[i][j]=dp[i-1][j]+a[i][j];
            }
            else {
                dp[i][j]=min(up,left)+a[i][j];
            }
        }
    }
    return dp[n-1][n-1];
}
signed main() {
	int n;
    cin>>n;
    vector<string>a(n);
    for(string &x:a)cin>>x;
    cout<<solve(n,a)<<endl;
}

