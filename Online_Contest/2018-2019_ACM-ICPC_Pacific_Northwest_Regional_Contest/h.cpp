#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;

bool check[MAXN + 10];
bool isPrime[MAXN + 10];
int prime[MAXN + 10];
int tot;

void getPrime(int N = MAXN)
{
    memset(check, false, sizeof(check));
    tot = 0;
    for (int i = 2; i <= N; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            isPrime[i] = true;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > N) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}


int main(void)
{
    getPrime();
    int x;
    scanf("%d", &x);
    int ans = 0;
    while (x >= 4)
    {
        for (int i = 0; i < tot; i++)
        {
            if (isPrime[x - prime[i]])
            {
                int diff = x - 2 * prime[i];
                if (diff % 2 == 0)
                {
                    x = diff;
                    break;
                }
            }
        }
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}