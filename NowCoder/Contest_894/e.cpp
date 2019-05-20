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
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 5e6 + 10;
const int mod = 1e9 + 7;

struct Node
{
    ll mv_2, _2mvg, mg_2;
    Node()
    {
        mv_2 = _2mvg = mg_2 = 0;
    }
} bit[maxn];
int q, op;
ll v, m, t;

void add(ll pos, ll a, ll b, ll c)
{
    while (pos < maxn)
    {
        bit[pos].mv_2 += a;
        bit[pos]._2mvg += b;
        bit[pos].mg_2 += c;
        pos += pos & -pos;
    }
}

Node sum(ll pos)
{
    Node ret = Node();
    while (pos)
    {
        ret.mv_2 = (ret.mv_2 + bit[pos].mv_2) % mod;
        ret._2mvg = (ret._2mvg + bit[pos]._2mvg) % mod;
        ret.mg_2 = (ret.mg_2 + bit[pos].mg_2) % mod;
        pos -= pos & -pos;
    }
    return ret;
}

int main()
{
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%lld%lld%lld", &v, &t, &m);
            v = v - 10 * t;
            add(v + 2e6, (m * v * v) % mod, (2LL * m * v * 10 % mod + mod) % mod, m * 100 % mod);
        }
        else
        {
            scanf("%lld%lld", &v, &t);
            v = v - 10 * t + 2e6;
            Node ans = sum(v);
            ll sum = ans.mv_2 % mod;
            sum = (sum + ans._2mvg % mod * t % mod) % mod;
            sum = (sum + ans.mg_2 % mod * t % mod * t % mod) % mod;
            printf("%lld\n", (sum + mod) % mod);
        }
    }
    return 0;
}