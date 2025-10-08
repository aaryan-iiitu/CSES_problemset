#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    int mx=0;
    vector<int>freq(1e6+1,0);
    for(int &x:a){
        cin>>x;
        mx=max(mx,x);
        freq[x]++;
    }
    vector<int>totaldiv(mx+1,0);
    for(int i=1;i<=mx;i++){
        for(int j=i;j<=mx;j+=i){
            totaldiv[i]+=freq[j];
        }
    }
    vector<int>gcdval(mx+1,0);
    for(int i=1;i<=mx;i++){
        gcdval[i]=1LL*(totaldiv[i]-1)*(totaldiv[i])/2;
    }
    vector<int>exact(mx+1);
    for(int i=mx;i>=1;i--){
        int currcnt=gcdval[i];
        for(int j=2*i;j<=mx;j+=i)currcnt-=exact[j];
        exact[i]=currcnt;
    }
    cout<<exact[1]<<endl;
}
signed main() {
	// your code goes here
    solve();
}
