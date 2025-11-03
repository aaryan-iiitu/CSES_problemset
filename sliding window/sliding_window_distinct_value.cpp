#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int &x:a)cin>>x;
    map<int,int>mp;
    set<int>st;
    for(int i=0;i<k;i++){
        mp[a[i]]++;
        st.insert(a[i]);
    }
    cout<<st.size()<<" ";
    for(int i=k;i<n;i++){
        mp[a[i-k]]--;
        if(mp[a[i-k]]==0){
            mp.erase(a[i-k]);
            st.erase(a[i-k]);
        }
        mp[a[i]]++;
        st.insert(a[i]);
        cout<<st.size()<<" ";
    }
    cout<<endl;
}
int32_t main() {
	// your code goes here
    solve();
}
