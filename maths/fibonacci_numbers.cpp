#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl "\n"
#define matrix vector<vector<int>>
const int mod=1e9+7;

matrix matmul(matrix &transformed,matrix &original){
    matrix ans(2,vector<int>(2));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                ans[i][j]=(ans[i][j]+transformed[i][k]*original[k][j])%mod;
            }
        }
    }
    return ans;
}
matrix binexp(matrix &a,int power){
    if(power==0){
        matrix identity(2,vector<int>(2));
        identity[0][0]=1;
        identity[1][1]=1;
        return identity;
    }
    matrix ans=binexp(a,power/2);
    matrix result=matmul(ans,ans);
    if(power&1){
        result=matmul(result,a);
    }
    return result;
}
void solve() {
    int n;
    cin >> n;
    if(n==0){
        cout<<0<<nl;
        return;
    }
    matrix T = {{1, 1}, {1, 0}};
    matrix mat = {{1}, {0}};
    matrix transformed=binexp(T,n-1);
    matrix  ans=matmul(transformed,mat);
    cout<<ans[0][0]<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
