#include <map>
#include <set>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
#define For(i, x, y) for(int i=x;i<=y;i++)
#define _For(i, x, y) for(int i=x;i>=y;i--)
#define Mem(f, x) memset(f,x,sizeof(f))
#define Sca(x) scanf("%d", &x)
#define Sca2(x,y) scanf("%d%d",&x,&y)
#define Sca3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define Scl(x) scanf("%lld",&x)
#define Pri(x) printf("%d\n", x)
#define Prl(x) printf("%lld\n",x)
#define CLR(u) for(int i=0;i<=N;i++)u[i].clear();
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define PII pair<int,int>
#define PIL pair<int,long long>
#define PLL pair<long long,long long>
#define pb push_back
#define fi first
#define se second
typedef vector<int> VI;
const int MAXBUF = 10000; char buf[MAXBUF], *ps = buf, *pe = buf + 1;
inline bool isdigit(const char &n) {
    return (n >= '0' && n <= '9');
}
inline void rnext() {
    if (++ps == pe)pe = (ps = buf) + fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
}
template <class T> inline bool in(T &ans) {
#ifdef VSCode
    ans = 0; T f = 1; register char c;
    do {
        c = getchar();
        if ('-' == c)f = -1;
    } while (!isdigit(c) && c != EOF);
    if (c == EOF)return false; do {
        ans = (ans << 1) + (ans << 3) + c - 48;
        c = getchar();
    } while (isdigit(c) && c != EOF); ans *= f; return true;
#endif
#ifndef VSCode
    ans = 0; T f = 1; if (ps == pe)return false; do {
        rnext();
        if ('-' == *ps)f = -1;
    } while (!isdigit(*ps) && ps != pe); if (ps == pe)return false; do {
        ans = (ans << 1) + (ans << 3) + *ps - 48;
        rnext();
    } while (isdigit(*ps) && ps != pe); ans *= f; return true;
#endif
} const int MAXOUT = 10000;
char bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
inline void write() {
    fwrite(bufout, sizeof(char), pout - bufout, stdout);
    pout = bufout;
}
inline void out_char(char c) {
    *(pout++) = c;
    if (pout == pend)write();
}
inline void out_str(char *s) {
    while (*s) {
        *(pout++) = *(s++);
        if (pout == pend)write();
    }
}
template <class T>inline void out_int(T x) {
    if (!x) {
        out_char('0');
        return;
    }
    if (x < 0)x = -x, out_char('-'); int len = 0; while (x) {
        outtmp[len++] = x % 10 + 48;
        x /= 10;
    } outtmp[len] = 0;
    for (int i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]); out_str(outtmp);
}
template<typename T, typename... T2>
inline int in(T &value, T2 &... value2) {
    in(value);
    return in(value2...);
}
int read() {
    int x = 0, f = 1; char c = getchar(); while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    } return x * f;
}
const double PI = acos(-1.0);
const double eps = 1e-9;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int N, M, K;
int a[maxn], id[maxn];
struct Tree {
    int l, r, Max;
} tree[maxn << 2];
inline void Pushup(int t) {
    tree[t].Max = max(tree[t << 1].Max, tree[t << 1 | 1].Max);
}
inline void Build(int t, int l, int r) {
    tree[t].l = l; tree[t].r = r;
    if (l == r) {
        tree[t].Max = id[l];
        return;
    }
    int m = l + r >> 1;
    Build(t << 1, l, m); Build(t << 1 | 1, m + 1, r);
    Pushup(t);
}
inline int query(int t, int l, int r) {
    if (l <= tree[t].l && tree[t].r <= r) {
        return tree[t].Max;
    }
    int m = (tree[t].l + tree[t].r) >> 1;
    if (r <= m) return query(t << 1, l, r);
    else if (l > m) return query(t << 1 | 1, l, r);
    return max(query(t << 1, l, m), query(t << 1 | 1, m + 1, r));
}
inline void update(int t, int p) {
    if (tree[t].l == tree[t].r) {
        tree[t].Max = INF;
        return;
    }
    int m = (tree[t].l + tree[t].r) >> 1;
    if (p <= m) update(t << 1, p);
    else update(t << 1 | 1, p);
    Pushup(t);
}
inline int solve(int k, int R) {
    int l = k, r = N + 1;
    int ans = N + 1;
    while (l <= r) {
        int m = l + r >> 1;
        if (query(1, k, m) > R) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}
int main() {
    int T;
    in(T);
    while (T--) {
        in(N); in(M);
        for (int i = 1; i <= N ; i ++) in(a[i]), id[a[i]] = i;
        id[N + 1] = INF;
        Build(1, 1, N + 1);
        int ans = 0;
        while (M--) {
            int op; in(op);
            if (op == 1) {
                int t; in(t);
                t ^= ans;
                update(1, a[t]);
            } else {
                int r, k; in(r); in(k);
                r ^= ans; k ^= ans;
                Pri(ans = solve(k, r));
            }
        }
    }
    return 0;
}