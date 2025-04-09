#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll &x:a)cin>>x;
    ll cnt=0;
    for(ll i=1;i<n;i++){
        if(a[i]>=a[i-1])continue;
        else {
            cnt+=abs(a[i]-a[i-1]);
            a[i]=a[i-1];
        }
    }
    cout<<cnt<<endl;
}
int main() {
	// your code goes here
    solve();
}
