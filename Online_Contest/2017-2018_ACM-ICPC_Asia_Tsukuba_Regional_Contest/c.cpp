#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define ff first
#define ss second

ll a[100010];
ll sum[100010];
int main() {
    ll n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum[i] = sum[i - 1] + a[i];
    ll ans, last = -1;
    for (int i = 1; i <= n; i++) {
        last = max(last, a[i]);
        ans = (t - sum[i - 1]) / last + 1 + ((t - sum[i - 1]) % last >= a[i]);

        ans = max(ans, 1ll);
        cout << ans << "\n";
    }
}