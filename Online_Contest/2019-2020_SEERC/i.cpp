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

int n, ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<int>a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    for (auto i : a) {
        int curr = INT_MAX;
        for (auto j : b) curr = min(curr, abs(i - j));
        ans = max(ans, curr);
    }
    cout << ans << endl;
    return 0;
}