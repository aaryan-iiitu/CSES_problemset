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
    seg[ind]=(seg[2*ind+1]+seg[2*ind+2]);
}
void update(int ind,int left,int right,int idx,int val){
    if(idx>right || idx<left)return ;
    if(left==right && left==idx){
        seg[ind]=val;
        return ;
    }
    int mid=(left+right)/2;
    update(2*ind+1,left,mid,idx,val);
    update(2*ind+2,mid+1,right,idx,val);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
int query(int ind,int left,int right,int l,int r){
    if(l>right || r<left)return 0;
    if(left >= l && right <= r) return seg[ind];
    int mid=(left+right)/2;
    return query(2*ind+1,left,mid,l,r)+query(2*ind+2,mid+1,right,l,r);
}
signed main() {
	// your code goes here
	
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>a[i];
    build(0,0,n-1);
    while(q--){
        int x,l,r;
        cin>>x>>l>>r;
        l--;
        if(x==2)r--;
        int ans;
        if(x==2)
        ans=query(0,0,n-1,l,r);
        else 
        update(0,0,n-1,l,r);
        if(x==2)
        cout<<ans<<endl;
    }
}
