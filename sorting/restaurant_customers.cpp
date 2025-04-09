#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
	// your code goes here
	ll n;
	cin>>n;
	vector<ll>a(n),b(n);

	for(ll i=0;i<n;i++){
	    cin>>a[i];
	    cin>>b[i];
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll i=0,j=0;
	ll cnt =0;
	ll maxi=0;
	while(i<n && j<n ){
	    if(a[i]<b[j]){
	        cnt++;
	        maxi=max(maxi,cnt);
	        i++;
	    }
	    else {
	        cnt--;
	        j++;
	    }
	}
	cout<<maxi<<endl;
	
	

}