#include <bits/stdc++.h>
using namespace std;
#define int long long 

int solve(int n){
    if(n==0)return 0;
    int high=-1;
    for(int i=60;i>=0;i--){
        if((1LL<<i)&n){
            high=i;
            break;
        }
    }
    int ans=high*(1LL<<(high-1))+(n-(1LL<<high)+1)+solve(n-(1LL<<high));
    return ans;
}
signed main() {
	// your code goes here
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
}
