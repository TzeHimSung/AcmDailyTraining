/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(p,b) sort(p+1,p+1+b)
#define rep1(i,p,b) for(int i=p;i<=b;++i)
#define rep0(i,p,b) for(int i=p;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e3 + 10;
struct Point {
    int x, y, z;
} p[maxn];
int n, l1 = INT_MAX, l2 = INT_MAX, r1 = -INT_MAX, r2 = -INT_MAX;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
    for (int i = 1; i <= n; i++) {
        l1 = min(p[i].x - p[i].z, l1); l2 = min(p[i].y - p[i].z, l2);
        r1 = max(p[i].x + p[i].z, r1); r2 = max(p[i].y + p[i].z, r2);
    }
    int currx = l1 + r1 >> 1, curry = l2 + r2 >> 1;
    int h1 = max(currx - l1, curry - l2), h2 = max(r1 - currx, r2 - curry);
    printf("%d %d %d\n", currx, curry, max(h1, h2));
    return 0;
}