#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll y,x;
    cin>>x>>y;
    ll maxi=max(x,y);
    if(maxi%2==0){
        if(x>=y){
            cout<<maxi*maxi-y+1<<endl;
        }
        else cout<<(maxi-1)*(maxi-1)+x<<endl;
    }
    else {
        if(x>=y){
            cout<<(maxi-1)*(maxi-1)+y<<endl;
        }
        else cout<<maxi*maxi-x+1<<endl;
    }
}
int main() {
	ll t;
	cin>>t;
	while(t--){
	    solve();
	}
}
