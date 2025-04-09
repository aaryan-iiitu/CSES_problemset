#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    int n;
    cin>>n;
    int xori=0;
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        xori^=x;
    }
    for(int i=1;i<=n;i++){
        xori^=i;
    }
    cout<<xori<<endl;
}