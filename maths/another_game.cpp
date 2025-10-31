#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        
        if(a[i]&1){
            cout<<"first"<<endl;
            return ;
        }
    }
    cout<<"second"<<endl;
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--)solve();
}
