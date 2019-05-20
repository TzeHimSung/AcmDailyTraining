#include <cstdio>

char A[1000002], B[1000002];
double f[1000002], p[1000002];

int main(void)
{
    int T;
    scanf("%d", &T);
    f[0] = 0; // joker in my hand.
    p[0] = 1; // joker in opp's hand.
    for (int i = 1; i <= 1000000; i++)
    {
        // 我赢的概率 = 1 - 对手在下一个状态下赢的概率
        f[i] = 1.0 - p[i - 1]; // 我一定会抽到一张好牌；
        //p[i] = 1.0 / (i + 1) * (1 - p[i]) // 我抽到了对面的鬼牌。
        //  + 1.0 * i / (i + 1) * (1 - f[i - 1]); // 我抽到了对面的好牌。
        p[i] = (1.0 + i - 1.0 * i * f[i - 1]) / (i + 2);
    }
    while (T--)
    {
        int n;
        scanf("%d", &n);
        scanf(" %s", A);
        scanf(" %s", B);
        int cnt = 0;
        bool myjoker = false;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == '1' && B[i] == '1')
            {
                cnt++;
            }
            else if (A[i] == '1')
            {
                myjoker = true;
            }
        }
        //printf("both: %d, myjoker: %d \n", cnt, myjoker ? 1 : 0);
        printf("%.10f\n", myjoker ? f[cnt] : p[cnt]);
    }
    return 0;
}