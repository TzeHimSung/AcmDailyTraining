#include <algorithm>
#include <cstdio>

const int N = 200005, inf = 1000000000;
char s[N], c[5] = {'2', '0', '1', '7', '6'};

struct Node {
    int f[5][5];
    void init() {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) f[i][j] = inf;
    }
} tr[N << 2], ans;

int find(char ch) { // 找字符ch在字符串c中出现的位置
    for (int i = 0; i < 5; i++)
        if (ch == c[i]) return i;
    return -1;
}

Node merge(Node a, Node b) {
    Node c; c.init();
    for (int i = 0; i < 5; i++)
        for (int j = i; j < 5; j++)
            for (int k = i; k <= j; k++)
                c.f[i][j] = std::min(c.f[i][j], a.f[i][k] + b.f[k][j]);
    return c;
}

void build(int now, int l, int r) { // 二分整个字符串
    tr[now].init();
    if (l == r) {
        int x = find(s[l]); //找到字符s[curl]在20176中出现的位置
        for (int i = 0; i < 5; i++) tr[now].f[i][i] = 0; //对角线为0？
        if (x >= 0 && x < 4) tr[now].f[x][x] = 1, tr[now].f[x][x + 1] = 0;
        if (x == 4) tr[now].f[3][3] = tr[now].f[4][4] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(now << 1, l, mid);
    build(now << 1 ^ 1, mid + 1, r);
    tr[now] = merge(tr[now << 1], tr[now << 1 ^ 1]);
}

void query(int now, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        if (x == l) ans = tr[now];
        else ans = merge(ans, tr[now]);
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) query(now << 1, l, mid, x, y);
    if (y > mid) query(now << 1 ^ 1, mid + 1, r, x, y);
}

int main() {
    int n, q;
    scanf("%d%d\n%s", &n, &q, s + 1); // 长度 查询次数 字符串
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int x, y; scanf("%d%d\n", &x, &y);
        query(1, 1, n, x, y);
        if (ans.f[0][4] >= inf) printf("-1\n");
        else printf("%d\n", ans.f[0][4]);
    }
}