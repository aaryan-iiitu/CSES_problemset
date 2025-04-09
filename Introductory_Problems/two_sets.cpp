#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n;
    cin>>n;
    int sum=n*(n+1)/2;
    if(sum&1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    if(n%2==0){
        cout<<n/2<<endl;
        vector<int>st1,st2;
        int i=1,j=n;
        bool fl=false;
        while(i<j){
            if(fl){
                st2.push_back(i);
                st2.push_back(j);
            }
            else {
                st1.push_back(i);
                st1.push_back(j);
            }
            i++;
            j--;
            fl=!fl;
        }
        for(auto it:st1){
            cout<<it<<" ";
        }
        cout<<endl;
        cout<<n/2<<endl;
        for(auto it:st2){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    if(n==3){
        cout<<1<<endl;
        cout<<3<<endl;
        cout<<2<<endl;
        cout<<1<<" "<<2<<endl;
        return;
    }
    set<int>st;
    vector<int>a;
    int sum1=0;
    for(int i=n;i>=1;i--){
        if((sum1+i)<=(sum)/2){
            sum1+=i;
            st.insert(i);
            a.push_back(i);
        }
    }
    cout<<a.size()<<endl;
    for(auto it:a){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<n-a.size()<<endl;
    for(int i=1;i<=n;i++){
        if(st.count(i)==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    
}
signed main() {
	// your code goes here
    solve();
}
