#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll &x:a){
        cin>>x;
    }
    ll maxi=LLONG_MIN,curr=0;
    for(ll i=0;i<n;i++){
        curr+=a[i];
        maxi=max(maxi,curr);
        if(curr<0)curr=0;
    }
    cout<<maxi<<endl;
}
int main() {
	// your code goes here
	solve();

}
