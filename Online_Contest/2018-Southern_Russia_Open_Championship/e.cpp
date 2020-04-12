#include <bits/stdc++.h>
using namespace std;
int checkStart(int x, int k) {
    x %= k;
    return x % 2 == 0 ? 1 : 0;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    if (n == 1) {
        printf("1");
        return 0;
    }
    int maxx = max((n + k - 1) / k, 2);
    if (maxx == 2 && k % 2 == 0) maxx++;
    for (int i = 0; i < n; ++i) {
        printf("%d ", (checkStart(i, k) + i / k) % maxx + 1);
    }
}