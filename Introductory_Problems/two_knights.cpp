#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
	// your code goes here
    int n;
    cin>>n;
    for(int k=1;k<=n;k++){
        cout<<(k*k)*(k*k-1)/2 - 4*(k-1)*(k-2)<<endl;
    }
}
