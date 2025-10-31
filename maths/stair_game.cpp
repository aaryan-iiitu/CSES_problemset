#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
 
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i&1)ans^=a[i];
    }
    if(ans==0)cout<<"second";
    else cout<<"first";
    cout<<endl;
    
}
signed main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--)solve();
}