#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
    int k;
    cin>>k;
    int start=1,cnt=9,len=1;
    while(k>start+cnt*len-1){
        start+=(cnt*len);
        len++;
        cnt*=10;
    }
    int first=pow(10,len-1);
    int offset=(k-start)/len;
    int target=first+offset;
    string ans=to_string(target);
    int target_digit=(k-start)%len;
    cout<<ans[target_digit]<<endl;
}
signed main() {
    int t;
    cin>>t;
    while(t--)
    solve();

}
