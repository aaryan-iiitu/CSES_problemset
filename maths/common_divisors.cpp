#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"



void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int &x:a)cin>>x;
    int ans=1;
    int mx=*max_element(a.begin(),a.end());
    vector<int>freq(mx+1,0);
    for(auto it:a)freq[it]++;
    for(int i=mx;i>=1;i--){
        int divisor=0;
        for(int j=i;j<=mx;j+=i){
            divisor+=freq[j];
        }
        if(divisor>=2){
            cout<<i<<endl;
            return ;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
        solve();
}