#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    map<ll,ll>mp;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]=i;
    }
    ll cnt=1;
    for(ll i=1;i<n;i++){
        if(mp[i]>mp[i+1])cnt++;
    }
    cout<<cnt<<endl;
    
}
int main() {
	// your code goes here
	solve();

}
