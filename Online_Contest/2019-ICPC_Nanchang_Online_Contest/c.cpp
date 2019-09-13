/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
char s[maxn], c[5] = {'2', '0', '1', '9', '8'};

struct Node {
    int f[5][5];
    void init() {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                f[i][j] = int_inf;
    }
} segt[maxn << 2], ans;

int find(char ch) {
    for (int i = 0; i < 5; i++)
        if (c[i] == ch) return i;
    return -1;
}

Node merge(const Node &a, const Node &b) {
    Node ret; ret.init();
    for (int i = 0; i < 5; i++)
        for (int j = i; j < 5; j++)
            for (int k = i; k <= j; k++)
                ret.f[i][j] = min(ret.f[i][j], a.f[i][k] + b.f[k][j]);
    return ret;
}

void build(int curpos, int curl, int curr) {
    segt[curpos].init();
    if (curl == curr) {
        int pos = find(s[curl]);
        for (int i = 0; i < 5; i++) segt[curpos].f[i][i] = 0;
        if (pos >= 0 && pos < 4) segt[curpos].f[pos][pos] = 1, segt[curpos].f[pos][pos + 1] = 0;
        if (pos == 4) segt[curpos].f[3][3] = segt[curpos].f[4][4] = 1;
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    segt[curpos] = merge(segt[lson], segt[rson]);
}

void query(int curpos, int curl, int curr, int ql, int qr) {
    if (ql <= curl && curr <= qr) {
        if (ql == curl) ans = segt[curpos];
        else ans = merge(ans, segt[curpos]);
        return;
    }
    int mid = curl + curr >> 1;
    if (ql <= mid) query(lson, curl, mid, ql, qr);
    if (qr > mid) query(rson, mid + 1, curr, ql, qr);
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    build(1, 1, n);
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        query(1, 1, n, x, y);
        if (ans.f[0][4] >= int_inf) puts("-1");
        else printf("%d\n", ans.f[0][4]);
    }
    return 0;
}