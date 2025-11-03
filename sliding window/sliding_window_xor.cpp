#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
    int n,k;
    cin>>n>>k;
    int x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<int>arr(n);
    arr[0]=x;
    for(int i=1;i<n;i++){
        arr[i]=(a*arr[i-1]+ b)%c;
    }
    int ans=0;
    vector<int>pre(n+1,0);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]^arr[i-1];
    }
    for(int i=k;i<=n;i++){
        ans=ans^(pre[i]^pre[i-k]);
    }
    cout<<ans<<endl;
}
int32_t main() {
	// your code goes here
    solve();
}
