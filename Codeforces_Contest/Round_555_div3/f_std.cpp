#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <assert.h>
typedef long long ll;
using namespace std;
typedef pair<int, int>pii;

const int N = 2e5 + 10;

int cnt[N], s[N];
int R[N];

int cal(int l, int r)
{
    return s[r] - s[l - 1];
}

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 200000; i >= 1; i--)
    {
        if (cnt[i + 1] == 0) R[i] = i;
        else if (cnt[i + 1] == 1) R[i] = i + 1;
        else R[i] = R[i + 1];
    }
    for (int i = 1; i <= 200000; i++) s[i] = s[i - 1] + cnt[i];
    pii ans = pii(-1, -1);
    for (int i = 1; i <= 200000; i++)
    {
        if (cnt[i] == 0) continue;
        if (cal(i, R[i]) > cal(ans.first, ans.second))
        {
            ans = pii(i, R[i]);
        }
    }
    int l = ans.first, r = ans.second;
    printf("%d\n", cal(l, r));
    printf("%d", l);
    cnt[l]--;
    for (int i = l + 1; i <= r; i++)
    {
        printf(" %d", i);
        cnt[i]--;
    }
    for (int i = r; i >= l; i--)
    {
        while (cnt[i]--) printf(" %d", i);
    }
    printf("\n");
}

int main()
{

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    solve();

    return 0;
}