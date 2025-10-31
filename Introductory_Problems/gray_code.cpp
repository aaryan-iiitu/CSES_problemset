#include <bits/stdc++.h>
using namespace std;

void f(int ind,int n,vector<string>&curr){
    if(ind>n)return ;
    vector<string>ans=curr;
    reverse(ans.begin(),ans.end());
    for(auto it:ans)curr.push_back(it);
    int sz=curr.size();
    for(int i=0;i<sz;i++){
        if(i<sz/2)curr[i]="0"+curr[i];
        else curr[i]="1"+curr[i];
    }
    f(ind+1,n,curr);
}
void solve(){
    int n;
    cin>>n;
    vector<string>curr={"0","1"};
    f(2,n,curr);
    for(auto it:curr)cout<<it<<endl;
    
}
int main() {
	solve();
}
