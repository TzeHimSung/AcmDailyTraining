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
    string s;
    cin >> s;
    int len = s.size(), ans = s.size();

    function<bool(int, int, int)> check = [&](int o, int p, int q)->bool{
        for (int i = o, j = q; i <= p; i++, j++) {
            if (s[i] != s[j]) return false;
        }
        return true;
    };

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int p = 1, q = j + 1;
            while (q - i + j < len) {
                if (check(i, j, q)) {
                    q += j - i + 1, p++;
                } else {
                    q++;
                }
            }
            ans = min(ans, len + p - (p - 1) * (j - i + 1));
        }
    }
    cout << ans << endl;

    return 0;
}