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

int n, k;

int main() {
    cin >> n >> k;
    int ans = 0;
    while (n) {
        ans++;
        n /= k;
    }
    cout << ans << endl;
    return 0;
}