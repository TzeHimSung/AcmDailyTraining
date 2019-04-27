#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <assert.h>
typedef long long ll;
using namespace std;

const int N = 205;

int a[N][N];
int b[N][N];
int n, m;

void cp()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) b[i][j] = a[i][j];
}

vector<int> cal(int r, int p)
{

    cp();
    vector<int>ans(n + m, 0);
    for (int i = 0; i < n; i++)
    {
        if (i == r) continue;
        for (int j = 0; j < m; j++)
        {
            if (b[r][j] == p) b[i][j] ^= 1;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (b[r][j] == p) ans[n + j] = 1, b[r][j] = (!p);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 1;
        for (int j = 1; j < m; j++)
        {
            if (b[i][j] == b[i][j - 1]) continue;
            else
            {
                flag = -1;
                break;
            }
        }
        if (flag == 1)
        {
            if (b[i][0]^cnt) ans[i] = 1;
            continue;
        }
        if (cnt) return vector<int>(n + m, -1);
        flag = 0;
        for (int j = 1; j < m; j++) if (b[i][j] != b[i][j - 1]) flag++;
        if (flag == 1)
        {
            if (b[i][0] == 1) ans[i] = 1;
            cnt = 1; continue;
        }
        else
        {
            return vector<int>(n + m, -1);
        }
    }
    return ans;
}

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }

    vector<int>ans;
    for (int i = 0; i < 4; i++)
    {
        ans = cal(i / 2, i & 1);
        if (ans[0] != -1)
        {
            printf("YES\n");
            for (int k = 0; k < n + m; k++)
            {
                printf("%d", ans[k]);
                if (k == n - 1) printf("\n");
            }
            printf("\n");
            return ;
        }
    }
    printf("NO\n");
}

int main()
{

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    solve();

    return 0;
}