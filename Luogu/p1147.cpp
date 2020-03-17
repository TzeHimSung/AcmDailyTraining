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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m; cin >> m;
    for (int i = (int)sqrt(2 * m); i > 1; i--) {
        if (2 * m % i == 0 && (2 * m / i + i) % 2) {
            cout << (2 * m / i - i + 1) / 2 << " " << (2 * m / i + i - 1) / 2 << endl;
        }
    }
    return 0;
}