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
    sort(a.begin(),a.end());
    ll val=1;
    for(ll i=0;i<n;i++){
        if(a[i]>val){
            cout<<val<<endl;
            return;
        }
        else val+=a[i];
    }
    cout<<val<<endl;
}
int main() {
	// your code goes here
	solve();

}
