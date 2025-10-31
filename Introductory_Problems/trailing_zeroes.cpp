#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int solve(int n){
    if(n==0)return 0;
    return n/5+ solve(n/5);
}
int main() {
	int n;
	cin>>n;
	cout<<solve(n)<<endl;

}
