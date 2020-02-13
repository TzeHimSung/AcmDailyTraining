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
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

int n, decr, high, expc, amount, price, cost;
map<int, int> m;

int main() {
    scanf("%d%d%d", &expc, &price, &amount);
    m[price] = amount;
    int pre = expc - 1, nxt = expc + 1, x, y;
    while (scanf("%d%d", &x, &y) && x != -1 && y != -1) {
        int k = (amount - y) / (x - price);
        if (price <= pre && pre <= x) m[pre] = y + k * (x - pre);
        if (price <= nxt && nxt <= x) m[nxt] = y + k * (x - nxt);
        if (price <= expc && expc <= x) m[expc] = y + k * (x - expc);
        price = x, amount = y;
    }
    scanf("%d", &decr);
    if (price < pre) m[pre] = amount - decr * (pre - price);
    if (price < nxt) m[nxt] = amount - decr * (nxt - price);
    if (price < expc) m[expc] = amount - decr * (expc - price);
    cost = m.begin() -> first;
    for (int i = 0;; i++) {
        int x = (pre - cost + i) * m[pre], y = (expc - cost + i) * m[expc], z = (nxt - cost + i) * m[nxt];
        if (x <= y && y >= z) {
            return printf("%d\n", i), 0;
        } else if (x > y) break;
    }
    for (int i = -1;; i--) {
        int x = (pre - cost + i) * m[pre], y = (expc - cost + i) * m[expc], z = (nxt - cost + i) * m[nxt];
        if (x <= y && y >= z) {
            return printf("%d\n", i), 0;
        }
    }
    return 0;
}