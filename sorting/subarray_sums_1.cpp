#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
  int n,k;
  cin>>n>>k;
  vector<int>a(n);
  map<int,int>mp;
  mp[0]=1;
  int sum=0;
  int cnt=0;
  for(int &x:a){
      cin>>x;
      sum+=x;
      if(mp.count(sum-k))cnt++;
      mp[sum]++;
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
