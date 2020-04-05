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

const int MAXN = 1e5 + 10;
int n, ans = 0;
string s[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    ans = s[n - 1][0] == 'T' ? 1 : 0;
    for (int i = n - 2; i >= 0; i--) {
        if (s[i][0] == 'L') ans ^= 1;
    }
    if (ans) cout << "TRUTH" << endl;
    else cout << "LIE" << endl;
    return 0;
}