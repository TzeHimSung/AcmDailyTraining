#include<bits/stdc++.h>
using namespace std;
int main() {
    int a, b, n; scanf("%d%d%d", &a, &b, &n);
    int c = b, d = a, ans = 0, cur = 1;
    while (c != n || d != n) {
        if (!cur) {
            c += b - a;
            if (c > n)c = n;
        } else {
            d += b - a;
            if (d > n)d = n;
        }
        cur ^= 1;
        ans++;
    }
    printf("%d\n", ans);
}