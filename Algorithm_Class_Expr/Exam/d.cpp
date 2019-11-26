#include <bits/stdc++.h>
#define ll long long

const int maxn = 1e5 + 10;
int n, m, a[maxn], ans = 0;

int check(int sumlim) {
    int segNum = 1, currSum = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] + currSum > sumlim) {
            segNum++; currSum = a[i];
        } else currSum += a[i];
    }
    if (segNum > m) return 0;
    else return 1;
}

int main() {
    scanf("%d%d", &n, &m);
    int l, r = INT_MAX;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < l) l = a[i];
    }
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}