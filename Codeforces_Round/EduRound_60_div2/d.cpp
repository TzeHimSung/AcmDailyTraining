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
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const ll mod = 1e9 + 7;
ll n, m;
int f[105];

struct Matrix
{
    static const int maxn = 1e2 + 10;
    ll num[maxn][maxn];

    Matrix()
    {
        rep0(i, 0, maxn)
        rep0(j, 0, maxn)
        num[i][j] = 0;
    }

    Matrix operator*(const Matrix &rhs)
    {
        Matrix ret;
        rep1(i, 1, m)
        rep1(j, 1, m)
        rep1(k, 1, m)
        ret.num[i][j] = (ret.num[i][j] + num[i][k] * rhs.num[k][j]) % mod;
        return ret;
    }

    Matrix &operator=(const Matrix &rhs)
    {
        rep1(i, 1, m)
        rep1(j, 1, m)
        num[i][j] = rhs.num[i][j];
        return *this;
    }

    Matrix pow_mod(ll k)
    {
        Matrix ret;
        rep1(i, 1, m) ret.num[i][1] = 1;
        while (k)
        {
            if (k & 1)
                ret = ret * (*this);
            (*this) = (*this) * (*this);
            k >>= 1;
        }
        return ret;
    }
};

int main()
{
    cin >> n >> m;
    if (m > n)
        return cout << 1, 0;
    rep0(i, 1, m) f[i] = 1;
    f[m] = 2;
    Matrix a; a.num[1][1] = a.num[1][m] = 1;
    rep1(i, 2, m)
    a.num[i][i - 1] = 1;
    Matrix b = a.pow_mod(n - m);
    ll ans = 0;
    rep1(i, 1, m)
    {
        ans += b.num[1][i] * f[m - i + 1];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}