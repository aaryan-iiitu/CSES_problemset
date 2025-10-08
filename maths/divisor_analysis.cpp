#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1e9+7;
int mul(int x,int y,int modulo)
{
	return ((x%mod)*(y%mod))%modulo;
}
int powers(int x,int p){
    x=x%mod;
    if(p==0) return 1;
    if(p==1) return x%mod;
    int z=powers(x,p/2);
    if(p%2>0) return mul(x,mul(z,z,mod),mod);
    return mul(z,z,mod);
}
int dividing(int x,int y){
    return mul(x,powers(y,mod-2),mod);
}
 
void solve() {
	
	 int x,k,n;
	 cin>>n;
	 int count=1,sum=1,product=1;
	 int count2=1;
	 for(int i=0;i<n;i++)
	 {
	 	
	 	cin>>x>>k;
	 	count= mul(count,k+1,mod);
	 	int current = (powers(x,k+1ll)-1ll+mod)%mod;
	 	int denom = (x-1+mod)%mod;
	 	sum = mul(sum,dividing(current,denom),mod);
	 	product =mul(powers(product,k+1),powers(powers(x,k*(k+1)/2),count2),mod);
	 	
	 	count2= mul(count2,k+1,mod-1);
 
	 }
	 cout<<count<<" "<<sum<<" "<<product<<"\n";
   
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
   // cin >> tests;
    while (tests--) {
        solve();
    }
    return 0;
}