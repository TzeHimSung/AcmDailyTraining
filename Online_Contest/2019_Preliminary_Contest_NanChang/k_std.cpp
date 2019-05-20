#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <assert.h>
typedef long long ll;
using namespace std;

const int N = 1e5 + 100;

int a[N];
int s[2][N];

int cal1(int l, int r)
{
    int i = (r - l) / 4;
    return s[1][l] ^ s[1][l + 4 * i + 4];
}

int cal2(int l, int r)
{
    int i = (r - l - 1) / 4;
    return s[0][l] ^ s[0][l + 4 * i + 4];
}

void solve()
{

    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n + 10; i++) s[0][i] = s[1][i] = a[i] = 0;

    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = n; i >= 1; i--)
    {
        s[1][i] = a[i] ^ s[1][i + 4];
        s[0][i] = a[i + 1] ^ s[0][i + 4];
    }
    int Q;
    scanf("%d", &Q);
    while (Q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int len = r - l + 1;
        if (len % 4 == 0)
        {
            printf("0\n");
            continue;
        }
        if (len == 1) printf("%d\n", a[l]);
        else if (len == 2) printf("%d\n", a[l]^a[l + 1]);
        else if (len == 3) printf("%d\n", a[l + 1]);
        else
        {
            int ans;
            if (len % 4 == 1) ans = cal1(l, r);
            else if (len % 4 == 2) ans = cal1(l, r)^cal2(l, r);
            else ans = cal2(l, r);
            printf("%d\n", ans);
        }
    }

}

int main()
{

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int T;
    scanf("%d", &T);
    while (T--) solve();

    return 0;
}