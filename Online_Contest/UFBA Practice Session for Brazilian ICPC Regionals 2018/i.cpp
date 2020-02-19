#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

int val[100010 << 2], pre[100010];
void upd(int x, int curl, int curr, int l, int v) {
    if (l == curl && curr == curl) {
        val[x] = v;
        return;
    }

    int mid = curl + curr >> 1;
    if (l <= mid)
        upd(x << 1, curl, mid, l, v);
    else
        upd(x << 1 | 1, mid + 1, curr, l, v);

    val[x] = max(val[x << 1], val[x << 1 | 1]);
}
int que(int x, int curl, int curr, int l, int r) {
    if (l <= curl && curr <= r) {
        //printf("que %d %d %d\n", curl, curr, val[x]);
        return val[x];
    }

    int mid = curl + curr >> 1;
    if (r <= mid)
        return que(x << 1, curl, mid, l, r);
    else if (l > mid)
        return que(x << 1 | 1, mid + 1, curr, l, r);
    else
        return max(que(x << 1, curl, mid, l, mid),
                   que(x << 1 | 1, mid + 1, curr, mid + 1, r));
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &pre[i]);
    for (int i = 1; i < n; i++)
        upd(1, 1, n - 1, i, abs(pre[i] - pre[i + 1]));
    while (q--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == 1) {
            pre[y] = z;
            if (y != 1)
                upd(1, 1, n - 1, y - 1, abs(pre[y - 1] - pre[y]));
            if (y != n)
                upd(1, 1, n - 1, y, abs(pre[y] - pre[y + 1]));
        } else {
            int ans = 1;
            if (y != 1) {
                int l = 1, r = y - 1, tmp = y;
                while (l <= r) {
                    int mid = l + r >> 1;
                    if (que(1, 1, n - 1, mid, y - 1) <= z)
                        r = mid - 1, tmp = min(tmp, mid);
                    else
                        l = mid + 1;
                }
                ans += y - tmp;
            }
            if (y != n) {
                int l = y, r = n - 1, tmp = y - 1;
                while (l <= r) {
                    int mid = l + r >> 1;
                    if (que(1, 1, n - 1, y, mid) <= z)
                        l = mid + 1, tmp = max(tmp, mid);
                    else
                        r = mid - 1;
                }
                ans += tmp - y + 1;
            }
            printf("%d\n", ans);
        }
    }
}