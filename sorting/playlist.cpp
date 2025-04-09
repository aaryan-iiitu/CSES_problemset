#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll &x:a)cin>>x;
    ll i=0,j=0;
    ll maxi=0;
    set<ll>st;
    while(i<n && j<n ){
        if(st.count(a[j])==0){
            st.insert(a[j]);
            maxi=max(maxi,j-i+1);
            j++;
        }
        else {
            while(st.count(a[j])!=0){
                st.erase(a[i]);
                i++;
            }
            st.insert(a[j]);
            maxi=max(maxi,j-i+1);
            j++;
        }
    }
    cout<<maxi<<endl;
}
int main() {
	// your code goes here
	solve();

}
