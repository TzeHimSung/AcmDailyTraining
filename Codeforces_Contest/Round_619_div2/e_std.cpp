#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int maxm = 10;
string s[maxn];
int R[4][maxn][maxn];
int n, m, q;
int val[maxn][maxn], f[maxm][maxm][maxn][maxn], lg[maxn];
void Build_2D_Sparse_Table(int n, int m) {
    int i, j, k1, k2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f[0][0][i + 1][j + 1] = val[i][j];
        }
    }

    for (i = 2; i < maxn; i++)
        lg[i] = 1 + lg[i / 2];

    for (i = 1; i <= n; i++)
        for (k2 = 1; (1 << k2) <= m; k2++)
            for (j = 1; j <= m - (1 << k2) + 1; j++)
                f[0][k2][i][j] = max(f[0][k2 - 1][i][j], f[0][k2 - 1][i][j + (1 << (k2 - 1))]);

    for (k1 = 1; (1 << k1) <= n; k1++)
        for (i = 1; i <= n - (1 << k1) + 1; i++)
            for (k2 = 0; (1 << k2) <= m; k2++)
                for (j = 1; j <= m - (1 << k2) + 1; j++)
                    f[k1][k2][i][j] = max(f[k1 - 1][k2][i][j], f[k1 - 1][k2][i + (1 << (k1 - 1))][j]);
}

int Query(int x1, int y1, int x2, int y2) {
    int k1 = lg[x2 - x1 + 1], k2 = lg[y2 - y1 + 1];
    x2 = x2 - (1 << k1) + 1;
    y2 = y2 - (1 << k2) + 1;
    return max(max(f[k1][k2][x1][y1], f[k1][k2][x1][y2]), max(f[k1][k2][x2][y1], f[k1][k2][x2][y2]));
}
void color(char c, int fx, int fy, int k) {
    int stx = 0, sty = 0;
    if (fx == -1)stx = n - 1;
    if (fy == -1)sty = m - 1;
    while (stx < n && stx >= 0) {
        while (sty < m && sty >= 0) {
            if (s[stx][sty] == c) {
                R[k][stx][sty] = 1;
                if (stx - fx >= 0 && stx - fx < n && sty - fy >= 0 && sty - fy < m) {
                    if (s[stx - fx][sty] == c && s[stx][sty - fy] == c && s[stx - fx][sty - fy] == c) {
                        R[k][stx][sty] = min(R[k][stx - fx][sty],
                                             min(R[k][stx][sty - fy], R[k][stx - fx][sty - fy])) + 1;
                    }
                }
            }
            sty += fy;
        }
        sty = 0; if (fy == -1)sty = m - 1;
        stx += fx;
    }

}
bool check(int r1, int c1, int r2, int c2, int mid) {
    r1 = r1 + mid - 1;
    c1 = c1 + mid - 1;
    r2 = r2 - mid;
    c2 = c2 - mid;
    if (r1 > r2 || c1 > c2)return false;
    return Query(r1, c1, r2, c2) >= mid;
}
int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    color('R', 1, 1, 0);
    color('Y', -1, 1, 1);
    color('G', 1, -1, 2);
    color('B', -1, -1, 3);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (s[i][j] == 'R' && s[i + 1][j] == 'Y' && s[i][j + 1] == 'G' && s[i + 1][j + 1] == 'B') {
                val[i][j] = min(R[0][i][j], min(R[1][i + 1][j], min(R[2][i][j + 1], R[3][i + 1][j + 1])));
            }
        }
    }
    Build_2D_Sparse_Table(n, m);
    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        int l = 0, r = min(r2 - r1, c2 - c1), ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(r1, c1, r2, c2, mid)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        printf("%d\n", ans * ans * 4);
    }
}