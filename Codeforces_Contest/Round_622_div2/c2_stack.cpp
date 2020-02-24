#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 500000 + 10;

struct Node {
    int val, cnt;
} a[maxn];

int m[maxn];
ll f[maxn], g[maxn];
int b[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &m[i]);
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (m[i] >= m[i - 1]) {
            a[++k] = (Node) {
                m[i], 1
            };
            f[i] = f[i - 1] + m[i];
        } else {
            ll sum = 0;
            int num = 0;
            while (k >= 1 && a[k].val >= m[i]) {
                sum += (ll)a[k].val * a[k].cnt;
                num += a[k].cnt; k--;
            }
            a[++k] = (Node) {
                m[i], num + 1
            };
            f[i] = f[i - 1] - sum + (ll)(num + 1) * m[i];
        }
    }
    k = 0;
    for (int i = n; i >= 1; i--) {
        if (m[i] >= m[i + 1]) {
            a[++k] = (Node) {
                m[i], 1
            };
            g[i] = g[i + 1] + m[i];
        } else {
            ll sum = 0;
            int num = 0;
            while (k >= 1 && a[k].val >= m[i]) {
                sum += (ll)a[k].val * a[k].cnt;
                num += a[k].cnt; k--;
            }
            a[++k] = (Node) {
                m[i], num + 1
            };
            g[i] = g[i + 1] - sum + (ll)(num + 1) * m[i];
        }
    }
    int id = 1;
    for (int i = 2; i <= n; i++) {
        if (f[i] + g[i] - m[i] > f[id] + g[id] - m[id])
            id = i;
    }
    b[id] = m[id];
    for (int i = id - 1; i >= 1; i--)
        b[i] = min(m[i], b[i + 1]);
    for (int i = id + 1; i <= n; i++)
        b[i] = min(m[i], b[i - 1]);
    for (int i = 1; i <= n; i++)
        printf("%d ", b[i]);
    printf("\n");
    return 0;
}