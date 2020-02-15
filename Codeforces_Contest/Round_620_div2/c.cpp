/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 110;
set<int>t;
map<int, int>l, h;
int q, n, m;

int main() {
    scanf("%d", &q);
    while (q--) {
        t.clear(), l.clear(), h.clear();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            int time, low, high;
            scanf("%d%d%d", &time, &low, &high);
            t.insert(time);
            if (!l.count(time)) {
                l[time] = low, h[time] = high;
            } else {
                l[time] = max(l[time], low), h[time] = min(h[time], high);
            }
        }
        int flag = 1, lastTime = 0, lastLow = m, lastHigh = m;
        for (auto currTime : t) {
            if (l[currTime] > h[currTime]) {
                flag = 0;
                break;
            }
            int deltaTemp = currTime - lastTime, currLow = l[currTime], currHigh = h[currTime];
            if (lastLow - deltaTemp <= currHigh && lastHigh + deltaTemp >= currLow) {
                lastLow = max(currLow, lastLow - deltaTemp);
                lastHigh = min(currHigh, lastHigh + deltaTemp);
                lastTime = currTime;
            } else {
                flag = 0;
                break;
            }
        }
        if (flag) puts("YES"); else puts("NO");
    }
    return 0;
}