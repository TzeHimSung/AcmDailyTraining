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
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
int n, k, p = 1, a[maxn], l[maxn], r[maxn], ans[maxn];
priority_queue<int>q;

int main()
{
    scanf("%d%d", &n, &k);
    l[0] = r[0] = 0; l[n + 1] = r[n + 1] = n + 1;
    rep1(i, 1, n)
    {
        int x; scanf("%d", &x);
        q.push(x);
        a[x] = i, l[i] = i - 1, r[i] = i + 1;
    }
    while (!q.empty() && p++)
    {
        while (!q.empty() && ans[a[q.top()]]) q.pop();
        if (q.empty()) break;
        int pos = a[q.top()]; q.pop();
        ans[pos] = p % 2 + 1;
        int lpos = pos, rpos = pos;
        rep1(i, 1, k)
        {
            lpos = l[lpos], rpos = r[rpos];
            ans[lpos] = ans[rpos] = p % 2 + 1;
        }
        l[r[rpos]] = l[lpos], r[l[lpos]] = r[rpos];
    }
    rep1(i, 1, n) printf("%d", ans[i]);
    puts("");
    return 0;
}