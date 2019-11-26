#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 10;
int n, a[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        scanf("%d", &a[n + 1]);
        sort(a + 1, a + 1 + n + 1);
        for (int i = 1; i < n + 1; i++) printf("%d ", a[i]);
        printf("%d\n", a[n + 1]);
    }
    return 0;
}