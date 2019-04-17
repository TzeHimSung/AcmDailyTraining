#include <cstdio>

long long int a[200], b[200];

int main(void)
{
    int T;
    while (scanf("%d", &T) != EOF)
    {
        while (T--)
        {
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%lld", &a[i]);
            }
            for (int i = 0; i < n; i++)
            {
                scanf("%lld", &b[i]);
            }
            bool flag = true;
            for (int i = n - 1; i >= 0; i--)
            {
                if (b[i] >= a[i])
                {
                    if (i)
                    {
                        b[i - 1] += b[i] - a[i];
                    }
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            printf(flag ? "Yes\n" : "No\n");
        }
    }
    return 0;
}