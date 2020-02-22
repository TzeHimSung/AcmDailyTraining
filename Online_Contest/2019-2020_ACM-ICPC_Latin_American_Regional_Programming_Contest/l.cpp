#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

char s[1010][1010];
int a[1010][1010], b[1010];
int d[20][10000];
int query(int l, int r) {
    int t = log2(r - l + 1);
    return min(d[t][l], d[t][r - (1 << t) + 1]);
}
void init(int len) {
    for (int i = 0; i < len; ++i) {
        d[0][i] = b[i];
    }
    int t = 1;
    for (int i = 1; t <= len; ++i) {
        for (int j = 0; j + t < len; ++j)
            d[i][j] = min(d[i - 1][j], d[i - 1][j + t]);
        t <<= 1;
    }
}
int main() {
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'G')
                a[i][j]++;
            a[i][j] += a[i][j - 1];
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            int l = j, r = m, mid, tmp = 0;
            while (l <= r) {
                mid = l + r >> 1;
                if (a[i][mid] - a[i][j - 1] == 0 || a[i][mid] - a[i][j - 1] == mid - j + 1)
                    l = mid + 1, tmp = max(tmp, mid);
                else
                    r = mid - 1;
            }
            b[i - 1] = tmp - j + 1;
        }
        init(n);
        for (int i = 1; i <= n; i++) {
            int l = 1, r = n - i + 1, mid, tmp = 1;
            while (l <= r) {
                mid = l + r >> 1;
                if (query(i - 1, i + mid - 2) >= mid)
                    l = mid + 1, tmp = max(tmp, mid);
                else
                    r = mid - 1;
            }
            ans = max(ans, tmp);
        }
    }
    printf("%d\n", ans * ans);
}