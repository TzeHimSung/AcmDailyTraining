#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <assert.h>
typedef long long ll;
using namespace std;

const int N = 105;
const int INF = 1e9 + 10;

int f[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6};

int ma[N * 7][10];
int mi[N * 7][10];

void init()
{
    for (int i = 0; i <= 700; i++)
    {
        for (int j = 0; j <= 9; j++) mi[i][j] = INF, ma[i][j] = -INF;
    }
    ma[0][0] = mi[0][0] = 0;

    for (int i = 1; i <= 700; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                if (i >= f[k])
                {
                    if (ma[i - f[k]][j - 1] < 0) continue;
                    if (k == 0)
                    {
                        if (j >= 2)
                            ma[i][j] = max(ma[i - f[k]][j - 1] * 10 + k, ma[i][j]);
                    }
                    else
                        ma[i][j] = max(ma[i - f[k]][j - 1] * 10 + k, ma[i][j]);
                }
            }
        }
    }
    for (int i = 1; i <= 700; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                if (i >= f[k])
                {
                    if (mi[i - f[k]][j - 1] >= INF) continue;
                    if (k == 0)
                    {
                        if (j >= 2)
                            mi[i][j] = min(mi[i - f[k]][j - 1] * 10 + k, mi[i][j]);
                    }
                    else
                        mi[i][j] = min(mi[i - f[k]][j - 1] * 10 + k, mi[i][j]);
                }
            }
        }
    }
}

int op[N];
int len[N];
char s[N];
ll dp[N][N * 7];

void solve()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int l = strlen(s);
    int tot = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '+') tot += 2;
        else if (s[i] == '-') tot++;
        else tot += f[s[i] - '0'];
    }
    int m = 0;
    for (int i = 0; i < l; i++)
    {
        int cur = 0;
        while (i < l && s[i] >= '0' && s[i] <= '9')
            cur++, i++;
        len[++m] = cur;
        if (i < l)
        {
            if (s[i] == '+') op[m + 1] = 1;
            else op[m + 1] = -1;
        }
    }
    /*
    cout<<tot<<endl;
    for(int i=1;i<=m;i++){
        cout<<op[i]<<' '<<len[i]<<endl;
    }
    */
    const ll inf = 1e13;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= tot; j++) dp[i][j] = -inf;
    }
    dp[0][0] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= tot; j++)
        {
            for (int k = 2 * len[i]; k <= 7 * len[i] && k <= j; k++)
            {
                if (i == 1)
                {
                    if (dp[i - 1][j - k] > -inf && ma[k][len[i]] >= 0)
                    {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + ma[k][len[i]]);
                    }
                }
                else
                {
                    if (k + 2 <= j && dp[i - 1][j - k - 2] > -inf && ma[k][len[i]] >= 0)
                    {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - k - 2] + ma[k][len[i]]);
                    }
                    if (i >= 2 && k + 1 <= j && dp[i - 1][j - k - 1] > -inf && mi[k][len[i]] < INF)
                    {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - k - 1] - mi[k][len[i]]);
                    }
                }
            }
        }
    }
    cout << dp[m][tot] << endl;
}

int main()
{

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    init();
    int T;
    scanf("%d", &T);
    while (T--) solve();

    return 0;
}