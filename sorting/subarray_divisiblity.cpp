#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
   int n;
   cin>>n;
   vector<int>a(n);
   for(int &x:a)cin>>x;
   int sum=0,cnt=0;
   map<int,int>mp;
   mp[0]=1;
   for(int i=0;i<n;i++){
       sum+=a[i];
       mp[(sum%n+n)%n]++;
   }
   for(auto [ind,val]:mp){
       cnt+=(val-1)*val/2;
   }
   cout<<cnt<<endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	//int t;
	//cin>>t;
	//while(t--){
	    solve();
	//}
    
}
