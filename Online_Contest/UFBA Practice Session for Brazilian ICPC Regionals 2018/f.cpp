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

const int maxn = 1e5 + 10;
int n, minSize, maxSize, a[maxn];
ll f[maxn];

void init() {
    for (int i = 0; i < maxn; i++) f[i] = 0;
}

void maintain(int l, int r) {
    if (l > r) return;
    f[l]++, f[r + 1]--;
}

bool check(int x) {
    init();
    f[1] = 1, f[2] = -1;
    queue<int>q;
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; i++) if (a[i] >= x) q.push(i);
    for (int i = 1; i <= n; i++) {
        f[i] += f[i - 1];
        while (!q.empty() && i > q.front()) q.pop();
        if (!f[i] || q.empty()) continue;
        if (i + maxSize - 1 < (int)q.front()) continue;
        maintain(max((int)q.front(), i + minSize - 1) + 1, min(n + 1, i + maxSize - 1 + 1));
    }
    f[n + 1] += f[n];
    return f[n + 1] > 0;
}

int main() {
    scanf("%d%d%d", &n, &minSize, &maxSize);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int l = 0, r = INT_MAX, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}