#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second
#define mp make_pair

int a[200010], b[200010], tmp[200010], ans[200010];
//
int main() {
    srand(time(0));
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int K = m / 4 + 1, cur = 0;
        for (int i = 1, x, y; i <= m; i++)
            scanf("%d%d", &a[i], &b[i]);
        while (1) {
            cur = 0;
            for (int i = 1; i <= n; i++) {
                tmp[i] = rand() & 1;
            }
            for (int i = 1; i <= m; i++)
                ans[i] = 0;
            for (int i = 1; i <= m; i++)
                if (tmp[a[i]] && !tmp[b[i]])
                    cur++, ans[i]++;
            if (cur >= K)
                break;
        }
        printf("%d\n", cur);
        for (int i = 1; i <= m; i++)
            if (ans[i])
                printf("%d ", i);
        printf("\n");
    }
}