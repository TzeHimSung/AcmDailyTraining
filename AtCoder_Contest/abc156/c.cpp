/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 110;
int n, a[maxn], ans = INT_MAX;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= 100; i++) {
        int tmp = 0;
        for (int j = 1; j <= n; j++) tmp += (a[j] - i) * (a[j] - i);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
