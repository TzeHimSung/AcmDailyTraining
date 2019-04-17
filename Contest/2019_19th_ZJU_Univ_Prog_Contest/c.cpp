#include <cstdio>

char t[2002][2002];
bool vis[2002][2002];

const int p3[] = {1, 3, 9, 27, 81, 243};

const int movement[4][2] =
{
    {1, 0}, // DOWN
    {0, 1},  // RIGHT
    {-1, 0}, // UP
    {0, -1} // LEFT
};

void init(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
        }
    }
}

int solve(void)
{
    int ans = 0;
    int n, m;
    int a, b;
    long long int k;
    scanf("%d %d", &n, &m);
    scanf("%d %d %lld", &a, &b, &k);
    a--;
    b--;
    char cmd[300];
    scanf(" %s", cmd);
    init(n, m);
    for (int i = 0; i < n; i++)
    {
        scanf(" %s", t[i]);
        for (int j = 0; j < m; j++)
        {
            t[i][j] -= '0';
        }
    }
    while (k--)
    {
        int x = p3[4] * t[a][b]
                + p3[3] * t[a - 1][b]
                + p3[2] * t[a + 1][b]
                + p3[1] * t[a][b - 1]
                + p3[0] * t[a][b + 1];
        if (vis[a][b])
        {
            return ans;
        }
        vis[a][b] = true;
        if (cmd[x] == 'D')
        {
            int na = a + movement[0][0], nb = b + movement[0][1];
            if (t[na][nb] == 1) return ans;
            else a = na, b = nb;
        }
        else if (cmd[x] == 'R')
        {
            int na = a + movement[1][0], nb = b + movement[1][1];
            if (t[na][nb] == 1) return ans;
            else a = na, b = nb;
        }
        else if (cmd[x] == 'U')
        {
            int na = a + movement[2][0], nb = b + movement[2][1];
            if (t[na][nb] == 1) return ans;
            else a = na, b = nb;
        }
        else if (cmd[x] == 'L')
        {
            int na = a + movement[3][0], nb = b + movement[3][1];
            if (t[na][nb] == 1) return ans;
            else a = na, b = nb;
        }
        else if (cmd[x] == 'P')
        {
            if (t[a][b] == 2)
            {
                t[a][b] = 0;
                ans++;
                init(n, m);
            }
        }
        else if (cmd[x] == 'I')
        {
            return ans;
        }
    }
    return ans;
}

int main(void)
{
    int T;
    while (scanf("%d", &T) != EOF)
    {
        while (T--)
        {
            printf("%d\n", solve());
        }
    }
    return 0;
}