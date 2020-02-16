#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

int f[100010];
int find(int x) {
    return f[x] != x ? f[x] = find(f[x]) : f[x];
}
void add(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy)
        f[fx] = fy;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; i++)
            f[i] = i;
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y);
        }
        while (q--) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (find(x) == find(y))
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
}
