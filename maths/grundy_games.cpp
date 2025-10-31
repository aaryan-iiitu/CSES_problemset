#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int lim=2001;
int dp[lim];
int mex(vector<int>&curr){
    set<int>st;
    for(auto it:curr)st.insert(it);
    int num=0;
    while(st.count(num)){
        num++;
    }
    return num;
}
void solve(){
    int n;
    cin>>n;
    if(n>=lim){
        cout<<"first"<<endl;
        return ;
    }
    if(dp[n]==0)cout<<"second";
    else cout<<"first";
    cout<<endl;
}
int main() {
	// your code goes here
	
	dp[0]=dp[1]=dp[2]=0;
	for(int i=3;i<lim;i++){
	    vector<int>curr;
	    for(int j=1;2*j<i;j++){
	        curr.push_back(dp[j]^dp[i-j]);
	    }
	    dp[i]=mex(curr);
	}
    int t;
    cin>>t;
    while(t--)solve();
}
