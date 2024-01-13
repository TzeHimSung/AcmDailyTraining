#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    int x = 0, y = 0, z = 0;

    double getDis(const Point& rhs) {
        return sqrt(pow(x - rhs.x, 2) + pow(y - rhs.y, 2) + pow(z - rhs.z, 2));
    }

    bool operator< (const Point& rhs) const {
        return z < rhs.z;
    }
};

void solve() {
    int n; cin >> n;
    vector<Point> a(n);
    for (int i = 0;i < n;i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    sort(a.begin(), a.end());
    double ans = 0;
    for (int i = 1;i < n;i++) {
        ans += a[i].getDis(a[i - 1]);
    }
    cout << fixed << setprecision(3) << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}