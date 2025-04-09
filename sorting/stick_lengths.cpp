#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll ans1=LLONG_MAX,ans2=LLONG_MAX;
    if(n&1){
        ans1=a[n/2];
        ll cnt=0;
        for(auto it:a){
            cnt+=abs(it-ans1);
        }
        cout<<cnt<<endl;
        return;
    }
    ll mid=(a[n/2]+a[(n/2)-1])/2;
    ll cnt=0;
    for(auto it:a){
        cnt+=abs(it-mid);
    }
    cout<<cnt<<endl;
}
int main() {
	// your code goes here
	solve();

}
