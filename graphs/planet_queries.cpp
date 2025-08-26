#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int N=2e5+5;
const int M=30;

int dp[N][M];
int n,q;
int f(int x,int k){
    for(int i=0;i<30;i++){
        if(k&(1LL<<i))x=dp[x][i];
    }
    return x;
}
signed main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
	    cin>>dp[i][0];
	}
	for(int i=1;i<30;i++){
	    for(int j=1;j<=n;j++){
	        dp[j][i]=dp[dp[j][i-1]][i-1];
	    }
	}
	while(q--){
	    int x,k;
	    cin>>x>>k;
	    cout<<f(x,k)<<endl;
	}
}
