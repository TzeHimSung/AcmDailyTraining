#include <iostream>
using namespace std;
long double c[501][501];
long double p[501];
void initC(int n) {
    for (int i = 0; i <= n; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
}
int main() {
    initC(500);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%Lf", &p[i]);
    for (int i = 0; i < n; ++i) {
        long double ans = 0;
        for (int j = 0; n - j >= k; ++j) {
            ans += c[n - 1 - j][k - 1] * p[(i - j + n) % n];
        }
        printf("%.12Lf ", ans / c[n][k]);
    }
}