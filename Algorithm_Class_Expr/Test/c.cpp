#include <bits/stdc++.h>

using namespace std;

const int maxn = 40;
long long a[maxn];

int main() {
    a[1] = 2;
    long long add = 6;
    for (int i = 2; i <= 35; i++) {
        a[i] = a[i - 1] + add;
        add *= 3;
    }
    int n;
    while (~scanf("%d", &n)) printf("%lld\n", a[n]);
    return 0;
}