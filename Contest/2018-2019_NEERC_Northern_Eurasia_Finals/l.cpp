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
#define int int32_t
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

const int maxn = 1e5 + 10;
int n, k, cnt = 0, m[maxn];
ll ans = 0;
struct Node
{
    int a, b;
};
Node p[maxn];

bool cmp(Node &a, Node &b)
{
    return a.b < b.b;
}

int main()
{
    init(m, 0);
    cin >> n >> k;
    rep1(i, 1, n)
    {
        cin >> p[i].a;
        m[p[i].a]++;
    }
    rep1(i, 1, n) cin >> p[i].b;
    sort(p + 1, p + 1 + n, cmp);
    rep1(i, 1, k)
    if (!m[i]) cnt++;
    rep1(i, 1, n)
    {
        if (!cnt) break;
        if (m[p[i].a] == 1) continue;
        m[p[i].a]--, cnt--;
        ans += p[i].b;
    }
    printf("%lld\n", ans);
    return 0;
}