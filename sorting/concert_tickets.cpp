#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n);
    multiset<ll>st;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    vector<ll>b(m);
    for(ll i=0;i<m;i++){
        cin>>b[i];
    }
    for(ll i=0;i<m;i++){
        auto it=st.upper_bound(b[i]);
        if(it==st.begin()){
            cout<<-1<<endl;
            continue;
        }
        it--;
        cout<<*it<<endl;
        st.erase(it);
    }
   
}
int main() {
	// your code goes here
	solve();
}
