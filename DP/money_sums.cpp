#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int>a(n);
	for(int &x:a)cin>>x;
	vector<int>dp(1e5+1,0);
	dp[0]=1;
	for(int i=0;i<n;i++){
	    vector<int>curr(1e5+1,0);
	    for(int j=0;j<=1e5;j++){
	        if(dp[j]){
	            curr[j]=1;
	            curr[j+a[i]]=1;
	        }
	    }
	    dp=curr;
	}
	int sum=accumulate(dp.begin()+1,dp.end(),0LL);
	cout<<sum<<endl;
	for(int i=1;i<=1e5;i++)if(dp[i])cout<<i<<" ";
    cout<<endl;
}
