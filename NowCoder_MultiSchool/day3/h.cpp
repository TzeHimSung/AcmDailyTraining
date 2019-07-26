#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<iostream>
#include<map>
using namespace std;


typedef long long ll;
const int maxn = 2e6 + 10;
struct Point {
    ll x, y;
} A[maxn];

ll Cal(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}
int n;
Point ans1;
Point ans2;

ll check(ll x) {
    ll num1 = 0; ll num2 = 0;
    bool flag = false;
    Point now;
    now.x = x;
    now.y = ans2.y;
    Point Or = now;
    Or.x -= ans1.x;
    Or.y -= ans1.y;
    for (int i = 1; i <= n; i++) {
        Point phi = A[i];
        phi.x -= ans1.x;
        phi.y -= ans1.y;
        if (Cal(Or, phi) > 0) {
            num1++;
        } else if (Cal(Or, phi) < 0) {
            num2++;
        }
    }
    if (num1 == num2) {
        return 0;
    } else if (num1 > num2) {
        return 1;
    } else if (num1 < num2) {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    ans1.x = -172337ll;
    ans1.y = -1001ll;
    ans2.y =  199997ll;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            ll x, y;
            cin >> x >> y;
            A[i].x = x;
            A[i].y = y;
        }
        ll l = 0; ll r = 1000000000ll;
        while (l <= r) {
            ll m = (l + r ) / 2;
            if (check(m) == 0) {
                ans2.x = m;
                break;
            } else if (check(m) < 0) {
                l = m + 1;
            } else if (check(m) > 0) {
                r = m - 1;
            }
        }
        cout << ans1.x << " " << ans1.y << " " << ans2.x << " " << ans2.y << endl;
    }
    return 0;
}