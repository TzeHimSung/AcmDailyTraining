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

const int maxn = 2e5 + 10;

struct Segment {
    int st, ed, len;
} seg[maxn];

struct Info {
    int isHori, len, slen, sign;
} cross[maxn];

int t, n, m, tree[maxn], pos[maxn];

int lowbit(int x) {
    return x & -x;
}

void init() {
    for (int i = 0; i < 100001; i++) tree[i] = 0;
}

void add(int x, int k) {
    for (; x < maxn; x += lowbit(x)) tree[x] += k;
}

int query(int x) {
    int ret = 0;
    for (; x; x -= lowbit(x)) ret += tree[x];
    return ret;
}

int cmp(int u, int v) {
    return mp(cross[u].len, cross[u].isHori) < mp(cross[v].len, cross[v].isHori);
}

bool check(int len) {
    init();
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (seg[i].ed - seg[i].st < len * 2) continue;
        cross[++cnt].slen = seg[i].len, cross[cnt].sign = 1, cross[cnt].isHori = 0, cross[cnt].len = seg[i].st + len;
        cross[++cnt].slen = seg[i].len, cross[cnt].sign = -1, cross[cnt].isHori = 0, cross[cnt].len = seg[i].ed - len + 1;
    }
    for (int i = n + 1; i <= n + m; i++) {
        if (seg[i].ed - seg[i].st < len * 2) continue;
        cross[++cnt].slen = seg[i].st + len, cross[cnt].sign = seg[i].ed - len, cross[cnt].isHori = 1, cross[cnt].len = seg[i].len;
    }
    for (int i = 1; i <= cnt; i++) pos[i] = i;
    sort(pos + 1, pos + cnt + 1, cmp);
    for (int l = 1, r = 1; l <= cnt; l = r) {
        for (; r <= cnt && cross[pos[l]].len == cross[pos[r]].len; r++) {
            if (!cross[pos[r]].isHori) add(cross[pos[r]].slen, cross[pos[r]].sign);
            else if (query(cross[pos[r]].slen - 1) < query(cross[pos[r]].sign)) return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d%d%d", &seg[i].st, &seg[i].ed, &seg[i].len);
        for (int i = n + 1; i <= n + m; i++) scanf("%d%d%d", &seg[i].st, &seg[i].ed, &seg[i].len);
        int l = 0, r = 5e4, ans;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(mid)) l = mid; else r = mid - 1;
        }
        ans = l;
        printf("%d\n", ans);
    }
    return 0;
}