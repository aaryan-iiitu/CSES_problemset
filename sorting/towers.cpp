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
    vector<ll>b;
    ll cnt=1;
    b.push_back(a[0]);
    for(ll i=1;i<n;i++){
        ll ind=upper_bound(b.begin(),b.end(),a[i])-b.begin();
        if(ind==b.size()){
            b.push_back(a[i]);
            cnt++;
        }
        else {
            b[ind]=a[i];
        }
    }
    cout<<cnt<<endl;
}
int main() {
	// your code goes here
	solve();

}
