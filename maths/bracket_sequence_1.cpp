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
void solve(){
    int n;
    cin>>n;
    if(n&1){
        cout<<0<<endl;
        return ;
    }
    n/=2;
    vector<int>fact(2*n+1,1);
    for(int i=1;i<=2*n;i++){
        fact[i]=(fact[i-1]*(i))%mod;
    }
    int ans=1;
    ans=(ans*fact[2*n])%mod;
    int modinv=binexp(fact[n],mod-2);
    ans=(ans*modinv)%mod;
    ans=(ans*modinv)%mod;
    ans=(ans*binexp(n+1,mod-2))%mod;
    cout<<ans<<endl;
}
int32_t main() {
	
    solve();
}
