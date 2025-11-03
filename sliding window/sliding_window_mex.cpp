#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int &x:a)cin>>x;
    set<int>st;
    for(int i=0;i<=k;i++)st.insert(i);
    map<int,int>mp;
    for(int i=0;i<k;i++){
        if(st.count(a[i]))
        st.erase(a[i]);
        mp[a[i]]++;
    }
    cout<<*st.begin()<<" ";
    for(int i=k;i<n;i++){
        mp[a[i-k]]--;
        if(mp[a[i-k]]==0){
            mp.erase(a[i-k]);
            st.insert(a[i-k]);
        }
        mp[a[i]]++;
        if(st.count(a[i]))
        st.erase(a[i]);
        cout<<*st.begin()<<" ";
    }
    cout<<endl;
}
int32_t main() {
	// your code goes here
    solve();
}
