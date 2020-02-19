#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

ll mod = 1e9 + 7;
ll qp(ll base, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll ans = ((n - 3) % mod * qp(2, n) % mod + (3 + n) % mod) % mod;
        cout << ans << "\n";
    }
}