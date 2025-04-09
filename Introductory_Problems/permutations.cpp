#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n;
    cin>>n;
    if(n>1 && n<4){
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    
    for(ll i=2;i<=n;i+=2){
        cout<<i<<" ";
    }
    for(ll i=1;i<=n;i+=2){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main() {
	// your code goes here
    solve();
}
