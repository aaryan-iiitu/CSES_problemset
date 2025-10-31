#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
 
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    int ans=0;
    for(int &x:a){
        cin>>x;
        ans=ans^x;
    }
    if(ans==0){
        cout<<"second"<<endl;
    }
    else cout<<"first"<<endl;
}
signed main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--)solve();
}