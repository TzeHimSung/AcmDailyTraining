#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 101;
int n, a[maxn][maxn];

int main() {
    int T; scanf("%d", &T);
    for (int __case = 1; __case <= T; __case++) {
        printf("Case #%d: ", __case);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        int trace = 0, row = 0, col = 0;
        for (int i = 1; i <= n; i++) trace += a[i][i];
        for (int i = 1; i <= n; i++) {
            set<int>s;
            for (int j = 1; j <= n; j++) s.insert(a[i][j]);
            if (s.size() != n) row++;
        }
        for (int j = 1; j <= n; j++) {
            set<int>s;
            for (int i = 1; i <= n; i++) s.insert(a[i][j]);
            if (s.size() != n) col++;
        }
        printf("%d %d %d\n", trace, row, col);
    }
    return 0;
}