#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

char s[200010];
int a[200010];
int main() {
    int m;
    scanf("%s%d", s + 1, &m);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        s[i + n] = s[i];
    for (int i = 1; i <= 2 * n; i++)
        if (s[i] == 'E')
            a[++a[0]] = i;
    if (!a[0]) {
        printf("0\n");
        return 0;
    }
    int last = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[last] < i && last <= a[0])
            last++;
        if (last > a[0])
            break;
        ans += max(0, i + m - a[last]);
    }
    printf("%lld\n", ans);
}