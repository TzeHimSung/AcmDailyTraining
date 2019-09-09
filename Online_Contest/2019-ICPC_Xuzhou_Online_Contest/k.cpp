#include<bits/stdc++.h>

using namespace std;

const int maxn = 200000;

const double eps = 1e-3;
bool dcmp(double x, double y) {
    if (abs(x - y) < eps) {
        return true;
    } else {
        return false;
    }
}
struct Point {
    double x, y;
    bool operator == (Point rhs)const {
        return (dcmp(x, rhs.x) && dcmp(y, rhs.y));
    }
    bool operator < (Point rhs)const {
        if (dcmp(x, rhs.x)) {
            return y < rhs.y;
        } else {
            return x < rhs.x;
        }
    }
} P[maxn];
vector<Point> vec;
set<Point> S;
bool CMP(Point p1, Point p2) {
    if (dcmp(p1.x, p2.x)) {
        return p1.y < p2.y;
    } else {
        return p1.x < p2.x;
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> P[i].x >> P[i].y;
    }
    if (n == 1 || n == 2) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            Point val;
            val.x = P[i].x + P[j].x;
            val.y = P[i].y + P[j].y;
            val.x /= 2.0;
            val.y /= 2.0;
            vec.push_back(val);
        }
    }
    for (int i = 1; i <= n; i++) {
        vec.push_back(P[i]);
    }
    sort(vec.begin(), vec.end(), CMP);
    int mx = 0;
    int tot = 1;
    Point pos;
    for (int i = 1; i < vec.size(); i++) {
        if (mx < tot) {
            mx = tot;
            pos.x = vec[i].x;
            pos.y = vec[i].y;
        }
        if (vec[i] == vec[i - 1]) {
            tot++;
        } else {
            tot = 1;
        }
        if (mx < tot) {
            mx = tot;
            pos.x = vec[i].x;
            pos.y = vec[i].y;
        }
    }
    for (int i = 1; i <= n; i++) {
        S.insert(P[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        Point Sym;
        Sym.x = pos.x + (pos.x - P[i].x);
        Sym.y = pos.y + (pos.y - P[i].y);
        if (!S.count(Sym)) {
            ans ++ ;
        }
    }
    cout << ans << endl;
    return 0;
}