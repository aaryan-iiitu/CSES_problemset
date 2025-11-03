#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
    int n,k;
    cin>>n>>k;
    int x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<int>nums(n);
    nums[0]=x;
    for(int i=1;i<n;i++){
        nums[i]=(a*nums[i-1]+b)%c;
    }
    int ans=0;
    if(k==1){
        for(int i=0;i<n;i++)ans^=nums[i];
        cout<<ans<<endl;
        return ;
    }
    vector<int>pre(n),suff(n);
    pre[0]=suff[n-1]=x;
    for(int i=1;i<n;i++){
        pre[i]=(i%k==0?nums[i]:pre[i-1]|nums[i]);
    }
    
    for(int i=n-2;i>=0;i--){
        suff[i]=(i%k==(k-1)?nums[i]:nums[i]|suff[i+1]);
    }
    for(int i=k-1;i<n;i++){
        if(i%k==(k-1)){
            ans^=pre[i];
        }
        else {
            ans^=(suff[i-k+1]|pre[i]);
        }
    }
    cout<<ans<<endl;
    
}
int32_t main() {
	// your code goes here
    solve();
}
