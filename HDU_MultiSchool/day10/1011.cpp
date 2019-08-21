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
/* namespace */
using namespace std;
/* header end */


const int maxn = 3e5 + 10;
int num[maxn], n, k;

struct Treap {
    int tot1, tot2, s[maxn], ch[maxn][2], key[maxn], size[maxn], sum0[maxn], sum1[maxn];

    void init() {
        tot1 = tot2 = 0;
        size[0] = 0;
        ch[0][0] = ch[0][1] = 0;
        sum0[0] = sum1[0] = 0;
    }

    bool random(double p) {
        return (double)rand() / RAND_MAX < p;
    }

    int newnode(int val) {
        int r;
        if (tot2) r = s[tot2--];
        else r = ++tot1;
        size[r] = 1;
        key[r] = val;
        ch[r][0] = ch[r][1] = 0;
        sum0[r] = sum1[r] = 0;
    }

    void del(int r) {
        if (!r) return;
        s[++tot2] = r;
        del(ch[r][0]); del(ch[r][1]);
    }

    void push_up(int r) {
        int lson = ch[r][0], rson = ch[r][1];
        size[r] = size[lson] + size[rson] + 1;
        sum0[r] = __gcd(sum0[lson], sum0[rson]);
        sum1[r] = __gcd(sum1[lson], sum1[rson]);
    }

    void merge(int &p, int x, int y) {
        if (!x || !y) p = x | y;
        else if (random((double)size[x] / (size[x] + size[y]))) {
            merge(ch[x][0], ch[x][1], y);
            push_up(p = x);
        } else {
            merge(ch[y][0], x, ch[y][0]);
            push_up(p = y);
        }
    }

    void split(int p, int &x, int &y, int k) {
        if (!k) {
            x = 0, y = p;
            return;
        }
        if (size[ch[p][0]] >= k) {
            y = p;
            split(ch[p][0], x, ch[y][0], k);
            push_up(y);
        } else {
            x = p;
            split(ch[p][1], ch[x][1], y, k - size[ch[p][0]] - 1);
            push_up(x);
        }
    }

    void build(int &p, int l, int r) {
        if (l > r) return;
        int mid = l + r >> 1;
        p = newnode(num[mid]);
        build(ch[p][0], l, mid - 1); build(ch[p][1], mid + 1, r);
        push_up(p);
    }
} tr;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        tr.init();
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        tr.build(0, 1, n);

    }
    return 0;
}