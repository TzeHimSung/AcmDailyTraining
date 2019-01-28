/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdint>
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
#define ll_int 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 5e3 + 210;
int n, s[maxn][maxn], p[maxn], num = 0, ans = 1;
char cp;

void ins(int x, int y)
{
    int msk;
    for (cp = getchar();; cp = getchar())
    {
        if (cp >= '0' && cp <= '9')
        {
            msk = cp - '0';
            break;
        }
        if (cp >= 'A' && cp <= 'Z')
        {
            msk = 10 + cp - 'A';
            break;
        }
    }
    rep0(i, 0, 4)
    s[x][y + i] = (msk >> (3 - i) & 1);
}

int check(int x)
{
    int bs = x * x;
    for (int i = x; i <= n; i += x)
        for (int j = x; j <= n; j += x)
        {
            int k = s[i][j] - s[i - x][j] - s[i][j - x] + s[i - x][j - x];
            if (k && k != bs) return 0;
        }
    return 1;
}

int main()
{
    cin >> n;
    rep1(i, 1, n)
    for (int j = 1; j <= n; j += 4)
        ins(i, j);
    rep1(i, 1, n)
    rep1(j, 1, n)
    s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    int k = n;
    for (int i = 2; i * i <= k; i++)
        if (k % i == 0)
        {
            p[++num] = i;
            while (k % i == 0) k /= i;
        }
    if (k > 1)
        p[++num] = k;
    int j;
    rep1(i, 1, num)
    {
        for (k = p[i], j = k; n % j == 0; j *= k)
            if (!check(j)) break;
        ans *= j / k;
    }
    cout << ans << endl;
    return 0;
}