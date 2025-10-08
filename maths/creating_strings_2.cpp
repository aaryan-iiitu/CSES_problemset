#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

const int N=1e6+1;
const int mod=1e9+7;
int fact[N];
int invfact[N];
int binexp(int base,int power){
    if(power==0)return 1;
    int ans=binexp(base,power/2);
    int res=(ans*ans)%mod;
    if(power&1)res=(base*res)%mod;
    return res;
}
int ncr(int a,int b){
    int ans = fact[a];
    ans = (ans * invfact[b]) % mod;
    ans = (ans * invfact[a - b]) % mod;
    return ans;
}
void solve(){
    map<char,int>mp;
    string s;
    cin>>s;
    int n=s.size();
    for(auto it:s)mp[it]++;
    int ans=fact[n];
    for(auto it:mp){
        ans=(ans*invfact[it.second])%mod;
    }
    cout<<ans<<endl;
}
signed main() {
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++)fact[i]=(fact[i-1]*i)%mod;
    invfact[1000000]=binexp(fact[1000000],mod-2);
    for(int i=1000000-1;i>=0;i--){
        invfact[i]=(invfact[i+1]*(i+1))%mod;
    }
	int t=1;
	
	while(t--)
    solve();
}
