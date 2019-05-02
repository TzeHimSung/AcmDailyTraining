#include <cstdio>

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, st;
        int st1, st2, st3;
        scanf("%d", &n);
        printf("1 2 2 3\n");
        fflush(stdout);
        scanf("%d", &st1);
        printf("3 4 4 5\n");
        fflush(stdout);
        scanf("%d", &st2);
        if (st1 == st2)
        {
            printf("5 1 1 4\n");
            fflush(stdout);
            scanf("%d", &st3);
            if (st1 == st3)
            {
                printf("1 3 3 5\n");
                fflush(stdout);
                scanf("%d", &st);
            }
            else
            {
                printf("2 5 5 3\n");
                fflush(stdout);
                scanf("%d", &st);
            }
        }
        else
        {
            printf("5 3 3 1\n");
            fflush(stdout);
            scanf("%d", &st3);
            if (st1 == st3)
            {
                printf("1 5 5 2\n");
                fflush(stdout);
                scanf("%d", &st);
            }
            else
            {
                printf("1 5 1 4\n");
                fflush(stdout);
                scanf("%d", &st);
            }
        }
        for (int i = 6; i <= n; i++)
        {
            printf("%d 1 %d 2\n", i, i);
            fflush(stdout);
            scanf("%d", &st);
        }
    }
    return 0;
}