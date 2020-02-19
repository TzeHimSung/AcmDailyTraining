#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll ans = 0;
        for (ll base = 2, j = 1, p = 1; base <= n; base <<= 1, j++, p <<= 1) {
            ans += n / base * j * p;
        }
        cout << ans << "\n";
    }
}