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

int n, m, k, curx = 1, cury = 1;
struct Path {
    int n;
    string s;
    Path() {}
    Path(int _n, string _s): n(_n), s(_s) {}
};
vector<Path>ans;

int main() {
    ans.clear();
    scanf("%d%d%d", &n, &m, &k);
    if (k > 4 * n * m - 2 * n - 2 * m) return puts("NO"), 0;
    puts("YES");
    for (cury = 1; cury <= m; cury++) {
        if (!k) break;
        if (cury == 1) {
            int step = min(n - 1, k);
            k -= step;
            if (step) ans.pb(Path(step, "D"));
            if (k) {
                int step = min(n - 1, k);
                k -= step;
                if (step) ans.pb(Path(step, "U"));
            }
            continue;
        }
        // 往右走一格
        ans.pb(Path(1, "R"));
        k--;
        if (!k) break;
        int cnt = 0;
        while (k >= 3 && curx < n) {
            k -= 3; curx++; cnt++;
        }
        if (cnt) ans.pb(Path(cnt, "DLR"));
        if (curx == n) {
            // 走得到下面，尽量回去第一行
            int step = min(k, n - 1);
            if (step) ans.pb(Path(step, "U"));
            k -= step, curx -= step;
        } else {
            // 步数不够，走不到下面，结束
            if (k == 1) {
                ans.pb(Path(1, "D"));
                k--;
            } else if (k == 2) {
                ans.pb(Path(1, "D"));
                ans.pb(Path(1, "L"));
                k -= 2;
            }
            break;
        }
    }
    if (k) ans.pb(Path(k, "L"));
    printf("%d\n", (int)ans.size());
    for (auto i : ans) {
        printf("%d %s\n", i.n, i.s.c_str());
    }
    return 0;
}