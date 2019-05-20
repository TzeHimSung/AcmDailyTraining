#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn = 2000000;
int A[maxn];
int fg[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &A[i]);
            fg[i] = 0;
        }
        if (n <= 3)
        {
            printf("0\n");
            continue;
        }
        int ans = 0;
        for (int i = 2; i <= n - 1; i++)
        {
            if (A[i - 1] < A[i] && A[i] > A[i + 1])
            {
                ans ++;
                fg[i] = 1;
            }
        }
        int endflag = 0;
        for (int i = 2; i <= n - 2; i++)
        {
            if (fg[i] == 1 && fg[i + 2] == 1)
            {
                if (A[i] == A[i + 2])
                {
                    printf("%d\n", ans - 2);
                    endflag = 1;
                    break;
                }
            }
        }
        if (endflag) continue;
        for (int i = 2; i <= n - 2; i++)
        {
            if (fg[i] == 1)
            {
                if (A[i - 1] < A[i + 1] && A[i + 1] > A[i + 2])
                {
                    continue;
                }
                else if (A[i - 2] < A[i - 1] && A[i - 1] > A[i + 1])
                {
                    continue;
                }
                else
                {
                    printf("%d\n", ans - 1);
                    endflag = 1;
                    break;
                }
            }
        }
        if (endflag) continue;
        printf("%d\n", ans);
    }
    return 0;
}