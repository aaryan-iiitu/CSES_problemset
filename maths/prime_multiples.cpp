#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define endl "\n"


void solve() {
	 int n,k;
	 cin>>n>>k;
	 vector<int>a(k);
	 for(int &x:a)cin>>x;
	 int ans=0;
	 for(int i=0;i<(1LL<<k);i++){
	     int prod=1LL;
	     vector<int>curr;
	     for(int j=0;j<k;j++){
	         if((1LL<<j)&i){
	             curr.push_back(a[j]);
	             
	         }
	     }
	     for(int j=0;j<curr.size();j++){
	         if(prod>n/curr[j]){
	             prod=n+1;
	             break;
	         }
	         prod*=curr[j];
	     }
	     if(curr.size()%2==0)ans-=n/prod;
	     else ans+=n/prod;
	 }
	 ans+=n;
	 cout<<ans<<endl;
   
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
   // cin >> tests;
    while (tests--) {
        solve();
    }
    return 0;
}