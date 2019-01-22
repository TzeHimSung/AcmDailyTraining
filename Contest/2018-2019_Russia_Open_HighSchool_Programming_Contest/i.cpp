/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
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
// #define int int32_t
#define ll int64_t
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
#define inf 0x3f3f3f3f
#define lson curr<<1
#define rson curr<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e7 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n, l, r, a[maxn], c[maxn], minNum, ans, top;
unsigned int b[maxn], x, y, z;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        minNum = ans = INF, top = 0;
        cin >> n >> l >> r >> x >> y >> z >> b[1] >> b[2];
        rep1(i, 3, n) b[i] = b[i - 2] * x + b[i - 1] * y + z;
        rep1(i, 1, n)
        {
            a[i] = b[i] % (r - l + 1) + l;
            if (a[i] >= 0)
            {
                if (minNum < a[i]) ans = min(ans, minNum * a[i]);
                minNum = min(a[i], minNum);
                continue;
            }
            minNum = min(a[i], minNum);
            while (top && c[top] < a[i])
                ans = min(ans, c[top--] * a[i]);
            c[++top] = a[i];
        }
        if (ans == INF) puts("IMPOSSIBLE");
        else cout << ans << endl;
    }
    return 0;
}