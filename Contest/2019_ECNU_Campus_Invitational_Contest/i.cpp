#include<bits/stdc++.h>

using namespace std;

const int maxn = 2000;
const int INF = 1e5;

int A[maxn][maxn];
int f[maxn][maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, fg = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &A[i][j]);
                f[i][j] = A[i][j]; //copy
            }
        for (int i = 1; i <= n; i++)
        {
            f[i][i] = 0; //dui jiao must be zero
            for (int j = 1; j <= n; j++)
            {
                if (f[i][j] != -1 && f[j][i] != -1 && f[i][j] != f[j][i])
                {
                    fg = 1; goto mark;
                }
                if (f[i][j] == -1 && f[j][i] != -1)
                    f[i][j] = f[j][i];
                else if (f[i][j] == -1) f[i][j] = INF;
            }
        }
        //floyd
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    f[i][j] = min(f[i][k] + f[k][j], f[i][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (A[i][j] != -1 && f[i][j] != A[i][j])
                {
                    fg = 1;
                    goto mark;
                }
            }
mark:;
        if (fg) printf("NO\n");
        else
        {
            printf("YES\n");
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (j == 1) printf("%d", f[i][j]);
                    else
                    {
                        printf(" %d", f[i][j]);
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}