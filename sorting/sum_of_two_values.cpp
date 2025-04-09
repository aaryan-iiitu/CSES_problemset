#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll>a(n);
    map<ll,vector<ll>>mp;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]].push_back(i+1);
    }
    for(ll i=0;i<n;i++){
        ll rem=x-a[i];
        if(rem!=a[i] && mp.count(rem)){
            cout<<mp[a[i]][0]<<" "<<mp[rem][0];
            cout<<endl;
            return;
        }
        else if(rem==a[i] && mp[rem].size()>1){
            cout<<mp[rem][0]<<" "<<mp[rem][1];
            cout<<endl;
            return;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}
int main() {
	// your code goes here
	solve();

}
