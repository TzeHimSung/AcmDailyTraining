/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <climits>
#include <float.h>
#include <complex>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int MOD = 1e6 + 3;

//定义mod P意义下的运算
#include <unordered_map>
struct Mod
{
    const ll mod, sqrtMod;
    Mod(ll p): mod(p), sqrtMod(sqrt(p) + 0.5) {}

    ll add(ll a, ll b)const
    {
        return ((a + b) % mod + mod) % mod;
    }

    ll mul(ll a, ll b)const
    {
        while (a < 0) a += mod; while (b < 0) b += mod;
        return a * b % mod;
    }

    ll pow(ll a, ll b)const
    {
        ll ret = 1;
        for (a %= mod; b; b >>= 1, a = mul(a, a))
            if (b & 1)
                ret = mul(ret, a);
        return ret;
    }

    //乘法逆元
    ll inv(ll a)const
    {
        while (a < 0) a += mod;
        return pow(a, mod - 2);
    }

    ll log(ll a, ll b)const
    {
        unordered_map<ll, ll>x;
        for (ll i = 0, e = 1; i <= sqrtMod; i++, e = mul(e, a))
        {
            if (!x.count(e))
                x[e] = i;
        }
        for (ll i = 0, v = inv(pow(a, sqrtMod)); i <= sqrtMod; i++, b = mul(b, v))
        {
            if (x.count(b))
                return i * sqrtMod + x[b];
        }
        return -1;
    }
} m(MOD);

//拉格朗日插值法
#define X real()
#define Y imag()
class Lagrange
{
public:
    static vector<ll> solve(vector<complex<ll>> p)
    {
        vector<ll> ret(p.size()), sum(p.size());
        ret[0] = p[0].Y, sum[0] = 1;
        rep0(i, 1, p.size())
        {
            for (int j = p.size() - 1; j >= i; j--)
                p[j].imag(m.mul(p[j].Y - p[j - 1].Y, m.inv(p[j].X - p[j - i].X)));
            for (int j = i; ~j; j--)
            {
                sum[j] = m.add(j ? sum[j - 1] : 0, -m.mul(sum[j], p[i - 1].X));
                ret[j] = m.add(ret[j], m.mul(sum[j], p[i].Y));
            }
        }
        return ret;
    }
};

int main()
{
    vector<complex<ll>>v;
    for (ll i = 0, x; i < 11; i++)
    {
        printf("? %lld\n", i);
        fflush(stdout);
        scanf("%lld", &x);
        if (!x)
            return printf("! %lld\n", i), 0;
        v.push_back({i, x % m.mod});
    }
    vector<ll> ret = Lagrange().solve(v);
    for (ll i = 0; i < m.mod; i++)
    {
        ll sum = 0;
        for (ll j = 0, x = 1; j < ret.size(); j++, x = m.mul(x, i))
            sum = m.add(sum, m.mul(x, ret[j]));
        if (sum == 0)
            return printf("! %lld\n", i), 0;
    }
    puts("! -1");
    return 0;
}