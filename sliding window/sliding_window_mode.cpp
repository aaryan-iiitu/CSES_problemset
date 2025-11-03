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
    set<pair<int,int>>st;
    for(int i=0;i<k;i++){
        mp[a[i]]++;
        
    }
    for(auto it:mp){
        st.insert({it.second,-it.first});
    }
    cout<<-st.rbegin()->second<<" ";
    for(int i=k;i<n;i++){
        int out=a[i-k];
        int in=a[i];
        st.erase({mp[out],-out});
        mp[out]--;
        if(mp[out]>0){
            st.insert({mp[out],-out});
        }
        else mp.erase(out);
        mp[in]++;
        st.insert({mp[in],-in});
        cout<<-st.rbegin()->second<<" ";
    }
    cout<<endl;
    
}
int32_t main() {
	// your code goes here
    solve();
}
