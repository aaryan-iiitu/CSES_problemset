#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int &y:a)cin>>y;
    vector<pair<int,int>>dp(1<<n);
    dp[0]={1,0};
    for(int mask=1;mask<(1<<n);mask++){
        dp[mask]={21,0};
        for(int person=0;person<n;person++){
            if(mask&(1<<person)){
                auto [rides,weight]=dp[mask^(1<<person)];
                if(weight+a[person]>x){
                    rides++;
                    weight=min(weight,a[person]);
                }
                else {
                    weight+=a[person];
                }
                dp[mask]=min(dp[mask],{rides,weight});
            }
        }
    }
    cout<<dp[(1<<n)-1].first<<endl;
}
