#include <bits/stdc++.h>

using namespace std;

using ll = long long;

inline ll read()
{
    ll d = 0;
    char s = getchar();
    while (s < '0' || s > '9')
        s = getchar();
    while (s >= '0' && s <= '9')
    {
        d = d * 10 + s - '0';
        s = getchar();
    }
    return d;
}

const int maxn = 1e5 + 10;

ll sum[maxn << 2], sumn[maxn << 2], sume[maxn << 2], nei[maxn << 2], summan[maxn << 2];

int f[maxn], fsz[maxn];
ll fed[maxn];

int n, Q;

int find(int x)
{
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}

void pushup(int k)
{
    sum[k] = sum[k << 1] + sum[k << 1 | 1];
    sumn[k] = sumn[k << 1] + sumn[k << 1 | 1];
    sume[k] = sume[k << 1] + sume[k << 1 | 1];
    nei[k] = nei[k << 1] + nei[k << 1 | 1];
    summan[k] = summan[k << 1] + summan[k << 1 | 1];
}

void build(int k, int l, int r)
{
    if (l == r)
    {
        sumn[k] = sum[k] = l == 1 ? n : 0;
        sume[k] = 0;
        nei[k] = 0;
        summan[k] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    pushup(k);
}

void add(int k, int l, int r, int pos, int val, ll ve)
{
    if (l == r)
    {
        sum[k] += (ll) l * val;
        sumn[k] += val;
        sume[k] += ve;
        nei[k] = (ll) l * (l - 1) / 2 * sumn[k] - sume[k];
        summan[k] = (ll) l * (l - 1) / 2 * sumn[k];
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        add(k << 1, l, mid, pos, val, ve);
    else
        add(k << 1 | 1, mid + 1, r, pos, val, ve);
    pushup(k);
}

ll sn, sm, tn;
void query(int k, int l, int r, ll K)
{
    if (l == r)
    {
        int _l = 1, _r = sumn[k], ans = K ? 1 : 0;
        while (_l <= _r)
        {
            int mid = (_l + _r) >> 1;
            ll sp = sn + (ll) l * mid;
            ll g = sp * (sp - 1) / 2 - sm - (ll) l * (l - 1) / 2 * mid;
            // cerr << mid << ' ' << g << '\n';
            if (g <= K)
            {
                if (g < K)
                    ans = max(ans, mid + 1);
                else
                    ans = max(ans, mid);
                _l = mid + 1;
            }
            else
                _r = mid - 1;
        }
        tn += ans;
        return;
    }
    int mid = (l + r) >> 1;
    ll sp = sn + sum[k << 1 | 1];
    ll g = sp * (sp - 1) / 2 - summan[k << 1 | 1] - sm;
    if (g == K)
    {
        sn += sum[k << 1 | 1];
        tn += sumn[k << 1 | 1];
    }
    if (g < K)
    {
        sn += sum[k << 1 | 1];
        sm += summan[k << 1 | 1];
        tn += sumn[k << 1 | 1];
        query(k << 1, l, mid, K);
    }
    if (g > K)
        query(k << 1 | 1, mid + 1, r, K);
}

int main()
{
    int T = read();
    while (T--)
    {
        n = read(), Q = read();
        for (int i = 1; i <= n; ++i)
            f[i] = i, fsz[i] = 1, fed[i] = 0;
        build(1, 1, n);
        int bsz = n;
        for (int o = 0; o < Q; ++o)
        {
            int op = read();
            if (op == 1)
            {
                int x = read(), y = read();
                int dx = find(x), dy = find(y);
                if (dx == dy)
                {
                    fed[dx]++;
                    add(1, 1, n, fsz[dx], 0, 1);
                }
                else
                {
                    int ln1 = fsz[dx], ln2 = fsz[dy];
                    ll ed1 = fed[dx], ed2 = fed[dy];
                    add(1, 1, n, ln1, -1, -ed1);
                    add(1, 1, n, ln2, -1, -ed2);
                    add(1, 1, n, ln1 + ln2, 1, ed1 + ed2 + 1);
                    f[dx] = dy;
                    fsz[dy] += fsz[dx];
                    fed[dy] += fed[dx] + 1;
                    bsz--;
                }
            }
            else
            {
                ll K = read();
                int mi = max(bsz - K, 1LL);
                K -= nei[1];
                int ma;
                if (K <= 0)
                    ma = bsz;
                else
                {
                    sn = sm = tn = 0;
                    query(1, 1, n, K);
                    ma = bsz - tn + 1;
                    // cerr << "S : " << bsz << ' ' << sn << ' ' << tn << '\n';
                }
                printf("%d %d\n", mi, ma);
            }
        }
    }
}