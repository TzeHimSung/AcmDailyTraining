#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

ll a[5010][5010];
const int mod = 1e9 + 7;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == 1)
        printf("1\n");
    else if (n == 2)
        printf("%d\n", m - 1);
    else {
        for (int i = 1; i <= 5000; i++)
            a[1][i] = 1, a[2][i] = i - 1;
        for (int i = 3; i <= n; i++)
            for (int j = i; j <= m; j++) {
                int tmp = j - 1;
                while (tmp > 0) {
                    a[i][j] = (a[i][j] + a[i - 1][tmp] * 2 % mod - a[i - 2][tmp - 1] + mod) % mod;
                    tmp -= i;
                }
            }
        printf("%lld\n", a[n][m]);
    }
}