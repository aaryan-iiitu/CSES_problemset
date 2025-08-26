#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
  int n,q;
 
  
  cin>>n;
  cin>>q;
  vector<int>a(n);
  for(int &x:a)cin>>x;
  vector<int>pre(n+1,0);
  for(int i=0;i<n;i++){
      pre[i+1]=pre[i]^a[i];
  }
  
  while(q--){
      int l,r;
      cin>>l>>r;
      cout<<(pre[r]^pre[l-1])<<endl;
  }
   
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
