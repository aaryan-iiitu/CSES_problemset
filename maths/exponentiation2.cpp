#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int mod = 1e9 + 7;

// fast exponentiation with custom modulus
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
    int a, b, c;
    cin >> a >> b >> c;

    // Step 1: compute exponent = (b^c) mod (mod-1)
    int exp = binexp(b, c, mod - 1);

    // Step 2: compute a^exp mod mod
    int finalans = binexp(a, exp, mod);

    cout << finalans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
