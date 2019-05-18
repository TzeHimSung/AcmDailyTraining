#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int f[60][15000];
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        int num;
        scanf("%d", &num);
        for (int j = 1; j <= num; j++)
        {
            int x;
            scanf("%d", &x);
            f[i][x] = 1;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int flag = 0;
            for (int k = 1; k <= n; k++)
            {
                if (f[i][k] && f[j][k])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("impossible\n");
                return 0;
            }
        }
    }
    printf("possible\n");
    return 0;
}