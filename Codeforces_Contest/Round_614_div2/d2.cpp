#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll inf = 1e17;
ll x[105], y[105];
ll ax, ay, bx, by, a, b, t;
int n, ans = 0;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
    // 跑到直到爆边界
    while (x[n] < inf && y[n] < inf) {
        ++n;
        // 不符合要求
        if (x[n - 1] > (inf - bx) / ax + 1 || y[n - 1] > (inf - by) / ay + 1) {
            --n;
            break;
        }
        x[n] = ax * x[n - 1] + bx;
        y[n] = ay * y[n - 1] + by;
    }
    cin >> a >> b >> t;
    // 枚举每个点
    for (int i = 0; i <= n; ++i) {
        ll currDis = abs(x[i] - a) + abs(y[i] - b);
        if (currDis > t) continue;
        ll remainLen = t - currDis;
        // O(n^2)枚举前面的两点
        for (int l = 0; l <= i; ++l) {
            for (int r = i; r <= n; ++r) {
                currDis = abs(x[i] - x[l]) + abs(y[i] - y[l]);
                currDis = min(currDis, abs(x[i] - x[r]) + abs(y[i] - y[r]));
                currDis += abs(x[l] - x[r]) + abs(y[l] - y[r]);
                // 剩下的长度能走完则符合要求
                if (currDis <= remainLen) ans = max(ans, r - l + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}