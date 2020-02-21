#include <bits/stdc++.h>
using namespace std;
char lproj[201][201];
char fproj[201][201];
bool lsolid[201][201];
bool fsolid[201][201];

struct point {
    int x, y, z;
    point() {}
    point(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }
    bool operator < (const point &b) const {
        if (x != b.x) return x < b.x;
        if (y != b.y) return y < b.y;
        return z < b.z;
    }
};

vector<point> ans1, ans2;

bool check(int n, int m, int h) {
    for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y)
            for (int z = 0; z < h; ++z) {
                if (fproj[x][y] == '1' != fsolid[x][y]) {
                    return false;
                }
                if (lproj[x][z] == '1' != lsolid[x][z]) {
                    return false;
                }
            }
    return true;
}

int main() {
    int n, m, h;

    scanf("%d%d%d", &n, &m, &h);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            scanf(" %c", &fproj[i][j]);
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < h; ++j) {
            scanf(" %c", &lproj[i][j]);
        }
    for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y)
            for (int z = 0; z < h; ++z) {
                if (fproj[x][y] == '1' && lproj[x][z] == '1') {
                    ans2.push_back(point(x, y, z));
                }
            }

    for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y)
            for (int z = 0; z < h; ++z) {
                if (fproj[x][y] == '1' && lproj[x][z] == '1') {
                    if (!fsolid[x][y] && !lsolid[x][z]) {
                        ans1.push_back(point(x, y, z));
                        fsolid[x][y] = true;
                        lsolid[x][z] = true;
                    }
                }
            }
    for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y)
            for (int z = 0; z < h; ++z) {
                if (fproj[x][y] == '1' && lproj[x][z] == '1') {
                    if (!fsolid[x][y] || !lsolid[x][z]) {
                        ans1.push_back(point(x, y, z));
                        fsolid[x][y] = true;
                        lsolid[x][z] = true;
                    }
                }
            }
    sort(ans1.begin(), ans1.end());
    if (!check(n, m, h)) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", ans2.size());
    for (auto p : ans2) printf("%d %d %d\n", p.x, p.y, p.z);
    printf("%d\n", ans1.size());
    for (auto p : ans1) printf("%d %d %d\n", p.x, p.y, p.z);

}