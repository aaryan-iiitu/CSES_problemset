#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
    int a,b;
    cin>>a>>b;
    if((2*b-a)<0 || ((2*b-a)%3!=0)){
        cout<<"NO"<<endl;
        return ;
    }
    int y=(2*b-a)/3;
    int x=a-y;
    if(x<0 || (x%2==1)){
        cout<<"NO"<<endl;
        return ;
    }
    cout<<"YES"<<endl;
}
signed main() {
    int t;
    cin>>t;
    while(t--)solve();

}
