#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"


const int mod=1e9+7;
int binexp(int base,int power){
    if(power==0)return 1;
    int ans=binexp(base,power/2);
    int res=(ans*ans*1LL)%mod;
    if(power&1)res=(res*base)%mod;
    return res;
}
signed main() {
	// your code goes here
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        int ans=binexp(a,b);
        cout<<ans<<endl;
    }
}
