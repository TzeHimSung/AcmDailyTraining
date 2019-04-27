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
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
int a[maxn], b[maxn], ans[maxn], n, bb[maxn], p = 0;
map<int, int>m;
stack<int>ss;
set<int>sss;

int check()
{
    for (int i = 1; i <= n; i++) if (!ans[i]) return 0;
    return 1;
}

int main()
{
    int t; scanf("%d", &t);
    while (t--)
    {
        while (!ss.empty()) ss.pop();
        sss.clear();
        scanf("%d", &n);
        rep1(i, 1, n)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
            ans[i] = 0;
            m[a[i]]++;
        }
        sort(b + 1, b + n + 1);
        rep1(i, 1, n) if (a[i] == b[i]) ss.push(a[i]), sss.insert(a[i]); else bb[++p] = a[i];
        for (int i = n; i >= 1; i--)
        {
            if (ss.empty()) break;
            if (!sss.count(a[i]))
            {
                ans[i] = ss.top();
                ss.pop();
            }
        }
        sot(bb, p);
        for (int i = n; i >= 1; i--)
        {
            if (!ans[i])
            {
                ans[i] = bb[p--];
            }
        }
        if (check())
        {
            rep0(i, 1, n) printf("%d ", ans[i]);
            printf("%d\n", ans[n]);
        }
        else puts("Impossible");
    }
    return 0;
}