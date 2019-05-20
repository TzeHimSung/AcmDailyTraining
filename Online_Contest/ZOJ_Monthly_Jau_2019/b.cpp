#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int const N = 1e5 + 5;

struct edge
{
    int y, next;
} a[N], totx[N];
int lasta[N], ne, lastx[N], xne;
int n, m;

void add(int x, int y)
{
    a[++ne].y = y;
    a[ne].next = lasta[x];
    lasta[x] = ne;
}

void addtot(int y, int x)
{
    totx[++xne].y = x;
    totx[xne].next = lastx[y];
    lastx[y] = xne;
}

int solve(ll s)
{
    for (int i = 1; i <= n; ++i)
        lastx[i] = 0;
    xne = 0;
    int ret = 0, ansy = n;
    ll sumx = 0, sumy = 0, sump = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = lasta[i]; j != 0; j = a[j].next)
        {
            int y = a[j].y;
            if (y <= ansy)
            {
                sumx += i;
                sumy += y;
                ++sump;
                addtot(y, i);
            }
        }
        while (sump * (i + ansy) - sumx - sumy > s)
        {
            for (int j = lastx[ansy]; j != 0; j = totx[j].next)
            {
                int x = totx[j].y;
                sumx -= x;
                --sump;
                sumy -= ansy;
            }
            --ansy;
        }
        if (sump * (i + ansy) - sumx - sumy == s)
            ++ret;
    }
    return ret;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            lasta[i] = 0;
        ne = 0;
        //add point
        for (int i = 1; i <= m; ++i)
        {
            int x, y; cin >> x >> y;
            add(x, y);
        }
        int Q; cin >> Q;
        while (Q--)
        {
            ll x; cin >> x;
            printf("%d", solve(x));
            if (Q == 0)
                putchar('\n');
            else
                putchar(' ');
        }
    }
    fclose(stdin);
    return 0;
}