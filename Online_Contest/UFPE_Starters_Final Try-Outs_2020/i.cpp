#include <bits/stdc++.h>
using namespace std;
struct point {
    int x, v;
    point() {}
    point(int _x, int _v) {
        x = _x;
        v = _v;
    }
    bool operator<(const point &b)const {
        return v < b.v;
    }
};
point pts[2000000];
int f[2000000];
int Size[2000000];
int a[2000000];
int find(int u) {
    if (f[u] != u) f[u] = find(f[u]);
    return f[u];
}
int Union(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        Size[u] += Size[v];
        f[v] = u;
    }
    return u;
}
int main() {
    int s, n, m;
    scanf("%d%d%d", &s, &n, &m);
    int len = n * m;
    for (int i = 0; i < len; ++i) {
        scanf("%d", &a[i]);
        pts[i] = point(i, a[i]);
    }
    sort(pts, pts + len);
    for (int i = 0; i < len; ++i) {
        f[i] = i; Size[i] = 1;
    }
    int maxsize = 0;
    for (int k = len - 1; k >= 0; --k) {
        int i = pts[k].x;
        int v = pts[k].v;
        if (i - 1 >= 0 && (i / m) == ((i - 1) / m) && a[i - 1] >= v) Union(i, i - 1);
        if (i + 1 < len && (i / m) == ((i + 1) / m) && a[i + 1] >= v) Union(i, i + 1);
        if (i + m < len && a[i + m] >= v) Union(i, i + m);
        if (i - m >= 0 && a[i - m] >= v) Union(i, i - m);
        maxsize = max(maxsize, Size[find(i)]);
        if (maxsize >= s) {
            printf("%d\n", v);
            return 0;
        }
    }
}