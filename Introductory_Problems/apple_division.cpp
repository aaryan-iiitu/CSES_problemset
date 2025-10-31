#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=INT_MAX;
    for(int i=0;i<(1<<n);i++){
        int first=0,second=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))first+=a[j];
            else second+=a[j];
        }
        ans=min(ans,abs(first-second));
    }
    cout<<ans<<endl;
}
signed main() {
    solve();

}
