#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n,m;
    cin>>n>>m;
    vector<string>s(n);
    for(string &x:s)cin>>x;
    vector<char>options={'A','B','C','D'};
    vector<vector<char>>ans(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            set<char>st;
            st.insert(s[i][j]);
            if(i-1>=0)st.insert(ans[i-1][j]);
            if(j-1>=0)st.insert(ans[i][j-1]);
            for(auto it:options){
                if(st.count(it)==0){
                    ans[i][j]=it;
                    break;
                }
            }
        }
        
    }
    for(auto it:ans){
        for(auto i:it)cout<<i;
        cout<<endl;
    }
}
int main() {
	solve();
}
