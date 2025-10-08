#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N=1e6+1;
int divisors[N];

int binexp(int base, int power, int m) {
    int res = 1;
    base %= m;
    while (power > 0) {
        if (power & 1) res = (res * base) % m;
        base = (base * base) % m;
        power >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin>>n;
    cout<<divisors[n]<<endl;
}
void precomputeDivisors(){
    for(int i=1; i<N; ++i){
        for(int j=i; j<N; j+=i){
            divisors[j]++;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precomputeDivisors();
    int t;
    cin >> t;
    while (t--)
        solve();
}