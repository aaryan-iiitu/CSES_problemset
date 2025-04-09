#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
	// your code goes here
	ll n,m,k;
	cin>>n>>m>>k;
	vector<ll>a(n);
	for(ll i=0;i<n;i++){
	    cin>>a[i];
	}
	vector<ll>b(m);
	for(ll i=0;i<m;i++){
	    cin>>b[i];
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll cnt =0;
	ll i=0,j=0;
	while(i<n && j<m ){
	    if(abs(a[i]-b[j])<=k){
	        cnt++;
	        i++;
	        j++;
	    }
	    else if(a[i]<b[j]){
	        i++;
	        
	    }
	    else j++;
	}
	cout<<cnt<<endl;
}
