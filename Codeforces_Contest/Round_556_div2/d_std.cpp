#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e8;
vector<int>dat[26];
char s[N];
char t[3][1005];
int cnt[3];
int n, Q;

int dp[255][255][255];

int _find(int id, int pos)
{
    int ans = upper_bound(dat[id].begin(), dat[id].end(), pos) - dat[id].begin();
    if (ans == (int)dat[id].size()) return INF;
    else return dat[id][ans];
}

void _min(int &a, int b)
{
    a = min(a, b);
}

void add(int a, char ch)
{
    cnt[a]++;
    int C = cnt[a];
    t[a][C] = ch;
    if (a == 0)
    {
        for (int i = 0; i <= cnt[1]; i++)
        {
            for (int j = 0; j <= cnt[2]; j++)
            {
                dp[C][i][j] = INF;
                if (i && dp[C][i - 1][j] < n)
                {
                    _min(dp[C][i][j], _find(t[1][i] - 'a', dp[C][i - 1][j]));
                }
                if (j && dp[C][i][j - 1] < n)
                {
                    _min(dp[C][i][j], _find(t[2][j] - 'a', dp[C][i][j - 1]));
                }
                if (dp[C - 1][i][j] < n)
                {
                    _min(dp[C][i][j], _find(ch - 'a', dp[C - 1][i][j]));
                }
            }
        }
    }
    else if (a == 1)
    {
        for (int i = 0; i <= cnt[0]; i++)
        {
            for (int j = 0; j <= cnt[2]; j++)
            {
                dp[i][C][j] = INF;
                if (i && dp[i - 1][C][j] < n)
                {
                    _min(dp[i][C][j], _find(t[0][i] - 'a', dp[i - 1][C][j]));
                }
                if (j && dp[i][C][j - 1] < n)
                {
                    _min(dp[i][C][j], _find(t[2][j] - 'a', dp[i][C][j - 1]));
                }
                if (dp[i][C - 1][j] < n)
                {
                    _min(dp[i][C][j], _find(ch - 'a', dp[i][C - 1][j]));
                }
            }
        }
    }
    else
    {
        for (int i = 0; i <= cnt[0]; i++)
        {
            for (int j = 0; j <= cnt[1]; j++)
            {
                dp[i][j][C] = INF;
                if (i && dp[i - 1][j][C] <= n)
                {
                    _min(dp[i][j][C], _find(t[0][i] - 'a', dp[i - 1][j][C]));
                }
                if (j && dp[i][j - 1][C] <= n)
                {
                    _min(dp[i][j][C], _find(t[1][j] - 'a', dp[i][j - 1][C]));
                }
                if (dp[i][j][C - 1] <= n)
                {
                    _min(dp[i][j][C], _find(ch - 'a', dp[i][j][C - 1]));
                }
            }
        }
    }
}

void del(int a)
{
    int C = cnt[a];
    if (a == 0)
    {
        for (int i = 0; i <= cnt[1]; i++)
        {
            for (int j = 0; j <= cnt[2]; j++)
            {
                dp[C][i][j] = INF;
            }
        }
    }
    else if (a == 1)
    {
        for (int i = 0; i <= cnt[0]; i++)
        {
            for (int j = 0; j <= cnt[2]; j++)
            {
                dp[i][C][j] = INF;
            }
        }
    }
    else
    {
        for (int i = 0; i <= cnt[0]; i++)
        {
            for (int j = 0; j <= cnt[1]; j++)
            {
                dp[i][j][C] = INF;
            }
        }
    }
    cnt[a]--;
}

void solve()
{
    scanf("%d%d", &n, &Q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        dat[s[i] - 'a'].push_back(i);
    while (Q--)
    {
        char op[3], ch;
        int a;
        scanf("%s", op);
        if (op[0] == '+')
        {
            scanf("%d %c", &a, &ch);
            add(a - 1, ch);
        }
        else
        {
            scanf("%d", &a);
            del(a - 1);
        }
        if (dp[cnt[0]][cnt[1]][cnt[2]] <= n) printf("YES\n");
        else printf("NO\n");
    }
}

int main()
{

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    solve();

    return 0;
}