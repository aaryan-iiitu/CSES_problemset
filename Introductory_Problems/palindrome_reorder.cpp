#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    map<char,int>mp;
    for(auto it:s){
        mp[it]++;
    }
    int cnt=0;
    char ch;
    for(auto it:mp){
        if(it.second&1){
            cnt++;
            ch=it.first;
        }
    }
    if((n%2==1 && cnt>1) || (n%2==0 && cnt>0) || (n%2==1 && cnt==0)){
        cout<<"NO SOLUTION"<<endl;
        return ;
    }
    vector<char>ans(n);
    if(n&1){
        ans[n/2]=ch;
        mp[ch]--;
    }
    int i=0,j=n-1;
    for(auto it:mp){
        int cnt=it.second;
        bool fl=false;
        while(cnt--){
            if(fl){
                ans[i]=it.first;
                i++;
            }
            else {
                ans[j]=it.first;
                j--;
            }
            fl=!fl;
        }
    }
    string curr="";
    for(auto it:ans)curr+=it;
    cout<<curr<<endl;
}
signed main() {
    solve();

}
