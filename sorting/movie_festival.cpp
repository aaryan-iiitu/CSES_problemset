#include <bits/stdc++.h>
using namespace std;
#define ll long long 
static bool comp(pair<ll,ll>&a,pair<ll,ll>&b){
    
    return a.second<b.second;
}
void solve(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i].first;
        cin>>a[i].second;
    }
   sort(a.begin(),a.end(),comp);
   ll last=0;
   ll cnt=0;
   for( ll i=0;i<n;i++){
       if(a[i].first>=last ){
           
           cnt++;
           last=a[i].second;
       }
       
   }
  
   cout<<cnt<<endl;
}
int main() {
	// your code goes here
	solve();
}
