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
string s;
int len, ans, cnt[MAXN], vis[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    len = s.size();

    for (int i = 0; i < len; i++) cnt[i] = -1;

    function<int(int)> check = [&](int step)->int{
        for (int i = 0; i < len; i++) vis[i] = 0;
        for (int i = 0; i < len; i++) {
            if (!vis[i]) {
                for (int j = i;;) {
                    vis[j] = 1;
                    j = (j + step) % len;
                    if (i == j) break;
                }
                int flag = 1;
                for (int j = i;;) {
                    if (s[j] == 'P') {
                        flag = 0;
                        break;
                    }
                    j = (j + step) % len;
                    if (i == j) break;
                }
                if (flag) return 1;
            }
        }
        return 0;
    };

    for (int i = 1; i < len; i++) {
        int step = __gcd(len, i);
        if (cnt[step] == -1) cnt[step] = check(step);
        ans += cnt[step];
    }

    cout << ans << endl;
    return 0;
}