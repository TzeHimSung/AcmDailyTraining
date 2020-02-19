#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

int a[100010];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0, j = i - 1, add = 3;
        while (j <= n) {
            int r = j + add;
            if (r > n)
                r = n;
            ans += max(0, a[r] - a[j]);
            j += add;
            add += 3;
        }
        printf("%d\n", ans);
    }
}
