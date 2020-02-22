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

const double pi = acos(-1);
const int maxn = 2020;

struct Star {
    int x, y, b;
} star[maxn];
vector<double>k;
int n;

double getRad(int x, int y) {
    if (!y) return x > 0 ? 0 : pi;
    if (!x) return y > 0 ? pi / 2 : -pi / 2;
    double ans = atan(double(y) / x);
    return x > 0 ? ans : ans + pi;
}

bool check() {
    if (k.size() < 2) return true;
    double last = k.back() - pi * 2;
    for (auto x : k) {
        if (pi - x + last <= eps) return true;
        last = x;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &star[i].x, &star[i].y, &star[i].b);
        for (int j = 0; j < i; j++) {
            if (star[i].b > star[j].b) k.pb(getRad(star[i].x - star[j].x, star[i].y - star[j].y));
            else if (star[i].b < star[j].b) k.pb(getRad(star[j].x - star[i].x, star[j].y - star[i].y));
        }
    }
    sort(k.begin(), k.end());
    if (check()) puts("Y"); else puts("N");
    return 0;
}