#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    string s;
    cin>>s;
    ll n=s.size();
    ll i=0;
    ll maxi=0;
    while(i<n ){
        char ch=s[i];
        ll curr=0;
        while(i<n && s[i]==ch){
            curr++;
            i++;
        }
        maxi=max(maxi,curr);
    }
    cout<<maxi<<endl;
}
int main() {
	// your code goes here
	solve();

}
