#include <bits/stdc++.h>
using namespace std;
#define int long long 

static bool comp(vector<int>&a,vector<int>&b){
    return a[0]<b[0];
}
int f(int n,vector<vector<int>>&a,vector<int>&ind,int i,vector<int>&dp){
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
    int nottake=f(n,a,ind,i+1,dp);
    int next_ind=upper_bound(ind.begin()+i,ind.end(),a[i][1])-ind.begin();
    int take=a[i][2]+f(n,a,ind,next_ind,dp);
    return  dp[i]= max(take,nottake);
}
signed main() {
    int n;
    cin>>n;
    vector<vector<int>>a;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a.push_back({x,y,z});
    }
    sort(a.begin(),a.end(),comp);
    vector<int>ind;
    for(auto it:a){
        ind.push_back(it[0]);
    }
    vector<int>dp(n+1,-1);
	cout<<f(n,a,ind,0,dp)<<endl;
}

