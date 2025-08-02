#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

const int N=2e5+5;
int seg[4*N];
int a[N];
void build(int ind,int l,int r){
    if(l==r){
        seg[ind]=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(2*ind+1,l,mid);
    build(2*ind+2,mid+1,r);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}
int query(int ind,int left,int right,int l,int r){
    if(l>right || r<left)return INT_MAX;
    if(left >= l && right <= r) return seg[ind];
    int mid=(left+right)/2;
    return min(query(2*ind+1,left,mid,l,r),query(2*ind+2,mid+1,right,l,r));
}
signed main() {
	// your code goes here
	memset(seg,INT_MAX,sizeof(seg));
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>a[i];
    build(0,0,n-1);
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        int ans=query(0,0,n-1,l,r);
        cout<<ans<<endl;
    }
}
