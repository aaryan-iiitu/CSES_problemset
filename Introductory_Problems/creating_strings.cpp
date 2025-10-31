#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    set<string>ans;
    do{
        ans.insert(s);
    }while(next_permutation(s.begin(),s.end()));
    cout<<ans.size()<<endl;
    for(auto it:ans)cout<<it<<endl;
}
int main() {
	solve();
}
