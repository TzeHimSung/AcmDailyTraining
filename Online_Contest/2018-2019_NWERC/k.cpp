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

int n, m;
string a, b, tmp, ans = "";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> a >> b;
    tmp = a;
    reverse(b.begin(), b.end());
    reverse(tmp.begin(), tmp.end());
    int p = 0;
    for (int i = 0; i < m - n; i++) {
        int x = b[i] - tmp[p]; if (x < 0) x += 26;
        ans += (char)(x + 'a');
        tmp += ans[p++];
    }
    tmp += a;
    reverse(ans.begin(), ans.end());
    cout << ans << a << endl;
    return 0;
}