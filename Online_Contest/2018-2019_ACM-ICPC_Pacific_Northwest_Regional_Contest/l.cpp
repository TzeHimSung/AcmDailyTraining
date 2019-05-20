#include<cstdio>
#include<cstring>

using namespace std;
const int maxn = 200000;
struct Node
{
    int a, b;
} A[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &A[i].a, &A[i].b);
    }
    for (int ans = n; ans >= 1; ans--)
    {
        int tot = 0;
        for (int i = 1; i <= n; i++)
        {
            if (A[i].a <= ans && ans <= A[i].b)
            {
                tot++;
            }

        }
        if (tot == ans)
        {
            printf("%d\n", ans);
            return 0;
        }
    }
    printf("-1\n");


    return 0;
}