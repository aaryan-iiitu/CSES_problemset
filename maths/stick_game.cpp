#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
 
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(k);
    for(int &x:a)cin>>x;
    vector<int>dp(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            if(i-a[j]>=0 && dp[i-a[j]]==0){
                dp[i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dp[i])cout<<"W";
        else cout<<"L";
    }
    cout<<endl;
}
signed main() {
	// your code goes here
    int t=1;
   // cin>>t;
    while(t--)solve();
}