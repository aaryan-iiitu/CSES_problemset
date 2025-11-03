#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
    int n,k;
    cin>>n>>k;
    int x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<int>arr(n);
    arr[0]=x;
    for(int i=1;i<n;i++){
        arr[i]=(a*arr[i-1]+ b)%c;
    }
    int ans=0;
    deque<int>dq;
    for(int i=0;i<k;i++){
        while(!dq.empty() && arr[i]<arr[dq.back()])dq.pop_back();
        dq.push_back(i);
    }
    for(int i=k;i<n;i++){
        ans^=arr[dq.front()];
        if(!dq.empty() && i-k>=dq.front())dq.pop_front();
        while(!dq.empty() && arr[dq.back()]>=arr[i])dq.pop_back();
        dq.push_back(i);
    }
    ans^=arr[dq.front()];
    
    cout<<ans<<endl;
}
int32_t main() {
	// your code goes here
    solve();
}
