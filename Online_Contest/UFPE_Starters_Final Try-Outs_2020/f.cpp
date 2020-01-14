#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second

struct node {
    int l, r, h;
    int add;
    node() {}
    node(int _l, int _r, int _h, int _add): l(_l), r(_r), h(_h), add(_add) {}
};

const int N = 2e5 + 10;
int x[N];
ll sum[N << 2];
node q[N];
int mark[N << 2];

void pushup(int n, int left, int right) {
    if (mark[n])sum[n] = x[right + 1] - x[left];
    else if (left == right)sum[n] = 0;
    else sum[n] = sum[n << 1] + sum[n << 1 | 1];
}

void pushdown(int n) {
    mark[n << 1] += mark[n], mark[n << 1 | 1] += mark[n];
    mark[n] = 0;
}

void update(int l, int r, int add, int n, int left, int right) {
    if (l <= left && right <= r) {
        mark[n] += add;
        pushup(n, left, right);
        return;
    }
    int mid = left + right >> 1;
    if (l <= mid)update(l, r, add, n << 1, left, mid);
    if (mid < r)update(l, r, add, n << 1 | 1, mid + 1, right);
    pushup(n, left, right);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int l, r, h; scanf("%d%d%d", &l, &r, &h);
        x[2 * i - 1] = l; x[2 * i] = r;
        q[2 * i - 1] = node(l, r, 0, 1);
        q[2 * i] = node(l, r, h, -1);
    }
    sort(x + 1, x + 1 + 2 * n);
    sort(q + 1, q + 1 + 2 * n, [](node a, node b) {
        return a.h < b.h;
    });
    int cnt = 1;
    for (int i = 2; i <= 2 * n; i++)
        if (x[i - 1] != x[i])x[++cnt] = x[i];
    ll ans = 0;
    q[2 * n + 1].h = q[2 * n].h;

    for (int i = 1; i <= 2 * n; i++) {
        int l = lower_bound(x + 1, x + 1 + cnt, q[i].l) - x;
        int r = lower_bound(x + 1, x + 1 + cnt, q[i].r) - x - 1;
        update(l, r, q[i].add, 1, 1, cnt);
        ans += sum[1] * (q[i + 1].h - q[i].h);
    }
    printf("%lld\n", ans);
}