#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAX = 1e6 + 10;
const double PI = acos(-1.0);
typedef long long ll;
int X[MAX], Y[MAX];
struct lenka
{
    int l, r;
    ll ma, tag;
} A[MAX << 2];
void build(int k, int l, int r)
{
    A[k].l = l, A[k].r = r;
    A[k].ma = l;
    if(l == r)return;
    build(2 * k, l, (l + r) / 2);
    build(2 * k + 1, (l + r) / 2 + 1, r);
    A[k].ma = max(A[2 * k].ma, A[2 * k + 1].ma);
}
void add(int k, int x, int y, ll z)
{
    if(x == A[k].l && y == A[k].r)
    {
        A[k].tag += z;
        A[k].ma += z;
        return;
    }
    if(A[k].tag)
    {
        add(2 * k, A[2 * k].l, A[2 * k].r, A[k].tag);
        add(2 * k + 1, A[2 * k + 1].l, A[2 * k + 1].r, A[k].tag);
        A[k].tag = 0;
    }
    if(y <= A[2 * k].r)add(2 * k, x, y, z);
    else if(x >= A[2 * k + 1].l)add(2 * k + 1, x, y, z);
    else
    {
        add(2 * k, x, A[2 * k].r, z);
        add(2 * k + 1, A[2 * k + 1].l, y, z);
    }
    A[k].ma = max(A[2 * k].ma, A[2 * k + 1].ma);
}
ll askma(int k, int x, int y)
{
    if(x == A[k].l && y == A[k].r)return A[k].ma;
    if(A[k].tag)
    {
        add(2 * k, A[2 * k].l, A[2 * k].r, A[k].tag);
        add(2 * k + 1, A[2 * k + 1].l, A[2 * k + 1].r, A[k].tag);
        A[k].tag = 0;
    }
    if(y <= A[2 * k].r)return askma(2 * k, x, y);
    if(x >= A[2 * k + 1].l)return askma(2 * k + 1, x, y);
    return max(askma(2 * k, x, A[2 * k].r), askma(2 * k + 1, A[2 * k + 1].l, y));
}
ll BIT[MAX];
void add(int x, int y)
{
    while(x <= 1000000)
    {
        BIT[x] += y;
        x += x & (-x);
    }
}
ll ask(int x)
{
    ll tot = 0;
    while(x)
    {
        tot += BIT[x];
        x -= x & (-x);
    } return tot;
}
int main()
{
    build(1, 1, 1000000);
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++)
    {
        char s[4];
        scanf("%s", s);
        if(s[0] == '+')
        {
            scanf("%d%d", &X[i], &Y[i]);
            add(1, 1, X[i], Y[i]);
            add(X[i], Y[i]);
        }
        if(s[0] == '-')
        {
            scanf("%d", &X[i]);
            add(1, 1, X[X[i]], -Y[X[i]]);
            add(X[X[i]], -Y[X[i]]);
        }
        if(s[0] == '?')
        {
            scanf("%d", &X[i]);
            printf("%lld\n", askma(1, 1, X[i]) - X[i] - (ask(1000000) - ask(X[i])));
        }
    }
    return 0;
}