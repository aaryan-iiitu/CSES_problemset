#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int main() {
	int n;
	cin>>n;
	int ans=1;
	for(int i=1;i<=n;i++){
	    ans=(ans*2)%mod;
	}
	cout<<ans<<endl;

}
