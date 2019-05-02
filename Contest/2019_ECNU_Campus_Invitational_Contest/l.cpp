#include<bits/stdc++.h>

using namespace std;
int A[20];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 1; i <= 6; i++)
            scanf("%d", &A[i]);
        int ans = A[6];
        A[6] = 0;
        ans += A[5];
        A[1] -= A[5];
        ans += A[4];
        if (A[2] <= A[4])
        {
            A[4] -= A[2];
            A[2] = 0;
            A[1] -= A[4] * 2;
        }
        else
        {
            A[2] -= A[4];
        }
        ans += A[3] / 2;
        A[3] %= 2;
        if (A[3] == 1)
        {
            ans ++;
            int x = 3;
            if (A[2] >= 1)
            {
                A[2] --;
                x -= 2;
            }
            A[1] -= x;
        }
        ans += A[2] / 3;
        A[2] %= 3;
        if (A[2] >= 1)
        {
            ans ++;
            A[1] -= 6 - A[2] * 2;
        }
        if (A[1] >= 1) ans += (A[1] + 5) / 6;
        printf("%d\n", ans);
    }
    return 0;
}